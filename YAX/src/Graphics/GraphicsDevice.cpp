#include "Graphics/GraphicsDevice.h"

#include <exception>

#include "Graphics/ClearOptions.h"
#include "Graphics/ColorWriteChannels.h"
#include "Graphics/CullMode.h"
#include "GameWindow.h"
#include "Graphics/GraphicsAdapter.h"
#include "Graphics/GraphicsProfile.h"
#include "Graphics/VertexElementFormat.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/IndexElementSize.h"
#include "MathHelper.h"
#include "Graphics/PrimitiveType.h"
#include "Graphics/RenderTarget2D.h"
#include "Graphics/RenderTargetCube.h"
#include "Graphics/RenderTargetUsage.h"
#include "Vector4.h"
#include "Graphics/VertexDeclaration.h"
#include "Graphics/VertexBuffer.h"

namespace YAX
{
    GraphicsDevice::GraphicsDevice(GraphicsAdapter& adapter, YAX::GraphicsProfile profile, const YAX::PresentationParameters& params)
        : _adapter(&adapter),
        _presParams(params),
        _blendState(YAX::BlendState::Opaque),
        _blendStateOld(_blendState),
        _boundRenderTarget(nullptr),
        _depthStencilState(YAX::DepthStencilState::Default),
        _depthStencilStateOld(_depthStencilState),
        _displayMode(_adapter->CurrentDisplayMode()),
        _graphicsProfile(profile),
        _indices(nullptr),
        _msMask(-1),
        _msMaskOld(_msMask),
        _rasterState(YAX::RasterizerState::CullCounterClockwise),
        _rasterStateOld(_rasterState),
        _viewport(params.Bounds()),
        _viewportOld(_viewport),
        _scissorRect(_viewport.Bounds()),
        _scissorRectOld(_scissorRect)
    {
        ReferenceStencil(0);

        i32 maxTex;
        glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxTex);

        //XNA supports 16 textures at maximum.
        _textures = TextureCollection(MathHelper::Min(maxTex, 16));
        _samplers = SamplerStateCollection(MathHelper::Min(maxTex, 16));

        glGenVertexArrays(1, &_vao);
        glBindVertexArray(_vao);

        UpdateState(true);
    }

#pragma region Properties
    const GraphicsAdapter* GraphicsDevice::Adapter() const
    {
        return _adapter;
    }

    Color GraphicsDevice::BlendFactor() const
    {
        return _blendState.BlendFactor();
    }

    void GraphicsDevice::BlendFactor(Color c)
    {
        _blendState.BlendFactor(c);
    }

    YAX::BlendState* GraphicsDevice::BlendState()
    {
        return &_blendState;
    }

    void GraphicsDevice::BlendState(const YAX::BlendState& b)
    {
        _blendState = b;
    }

    YAX::DepthStencilState* GraphicsDevice::DepthStencilState()
    {
        return &_depthStencilState;
    }

    void GraphicsDevice::DepthStencilState(const YAX::DepthStencilState& d)
    {
        _depthStencilState = d;
    }

    YAX::DisplayMode GraphicsDevice::DisplayMode() const
    {
        return _displayMode;
    }

    YAX::GraphicsProfile GraphicsDevice::GraphicsProfile() const
    {
        return _graphicsProfile;
    }

    IndexBuffer* GraphicsDevice::Indicies()
    {
        return _indices;
    }

    void GraphicsDevice::Indicies(IndexBuffer& ib)
    {
        _indices = &ib;
    }

    i32 GraphicsDevice::MultiSampleMask() const
    {
        return _msMask;
    }

    void GraphicsDevice::MultiSampleMask(i32 mask)
    {
        _msMask = mask;
    }

    YAX::PresentationParameters& GraphicsDevice::PresentationParameters()
    {
        return _presParams;
    }

    YAX::RasterizerState GraphicsDevice::RasterizerState() const
    {
        return _rasterState;
    }

    void GraphicsDevice::RasterizerState(const YAX::RasterizerState& r)
    {
        _rasterState = r;
    }

    i32 GraphicsDevice::ReferenceStencil() const
    {
        return _refStencil;
    }

    void GraphicsDevice::ReferenceStencil(i32 rs)
    {
        _refStencil = rs;
    }

    Rectangle GraphicsDevice::ScissorRectangle() const
    {
        return _scissorRect;
    }

    void GraphicsDevice::ScissorRectangle(Rectangle r)
    {
        _scissorRect = r;
    }

    SamplerStateCollection& GraphicsDevice::Samplers()
    {
        return _samplers;
    }

    TextureCollection& GraphicsDevice::Textures()
    {
        return _textures;
    }

    YAX::Viewport GraphicsDevice::Viewport() const
    {
        return _viewport;
    }

    void GraphicsDevice::Viewport(YAX::Viewport v)
    {
        _viewport = v;
    }
#pragma endregion 

    void GraphicsDevice::Clear(const Color& clearColor) const
    {
        Clear(
            ClearOptions::Target | ClearOptions::Stencil | ClearOptions::DepthBuffer,
            clearColor.ToVector4(),
            _viewport.MaxDepth(),
            0
        );
    }

    void GraphicsDevice::Clear(ClearOptions options, const Color& clearColor, float depthVal, i32 stencilVal) const
    {
        Clear(options, clearColor.ToVector4(), depthVal, stencilVal);
    }

    void GraphicsDevice::Clear(ClearOptions options, const Vector4& clearColor, float depthVal, i32 stencilVal) const
    {
        glClearColor(clearColor.X, clearColor.Y, clearColor.Z, clearColor.W);
        glClearDepth(depthVal);
        glClearStencil(stencilVal);

        auto dsFmt = (_boundRenderTarget
            ? _boundRenderTarget->RenderTarget()->DepthStencilFormat()
            : _presParams.DepthStencilFormat()
            );

        //Make sure whatever's getting cleared has the correct buffers
        if ((options & ClearOptions::Stencil) == ClearOptions::Stencil
            && dsFmt != DepthFormat::Depth24Stencil8)
        {
            options &= ~ClearOptions::Stencil;
        }

        if ((options & ClearOptions::DepthBuffer) == ClearOptions::DepthBuffer
            && dsFmt == DepthFormat::None)
        {
            options &= ClearOptions::Target;
        }

        glClear((GLenum)options);
    }

    void GraphicsDevice::ApplyFullscreen(GameWindow* win)
    {
        win->BeginScreenDeviceChange(_presParams.IsFullScreen());
        win->EndScreenDeviceChange(_adapter->MonitorIndex());
    }

    i32 GraphicsDevice::CalcPrimTypeVertices(PrimitiveType pt, i32 primCount)
    {
        switch (pt)
        {
            case PrimitiveType::LineList:
                return primCount * 2;
                break;
            case PrimitiveType::LineStrip:
                primCount + 1;
                break;
            case PrimitiveType::TriangleList:
                primCount * 3;
                break;
            case PrimitiveType::TriangleStrip:
                primCount + 2;
                break;
        }
    }

    void GraphicsDevice::UpdateState(bool forceUpdate)
    {
    #pragma region BlendState
        if (forceUpdate 
            || _blendState._alphaBlendFunc != _blendStateOld._alphaBlendFunc
            || _blendState._colorBlendFunc != _blendStateOld._colorBlendFunc)
        {
            if (_blendState._alphaBlendFunc == _blendState._colorBlendFunc)
                glBlendEquation((GLenum)_blendState._alphaBlendFunc);
            else
                glBlendEquationSeparate((GLenum)_blendState._colorBlendFunc, (GLenum)_blendState._alphaBlendFunc);
        }

        if (forceUpdate
            || _blendState._alphaSrcBlend != _blendStateOld._alphaSrcBlend
            || _blendState._alphaDestBlend != _blendStateOld._alphaDestBlend
            || _blendState._colorSrcBlend != _blendStateOld._colorSrcBlend
            || _blendState._colorDestBlend != _blendStateOld._colorDestBlend)
        {
            if (_blendState._alphaSrcBlend == _blendState._colorSrcBlend
                && _blendState._alphaDestBlend == _blendState._colorDestBlend)
                glBlendFunc((GLenum)_blendState._alphaSrcBlend, (GLenum)_blendState._alphaDestBlend);
            else
                glBlendFuncSeparate(
                    (GLenum)_blendState._colorSrcBlend, 
                    (GLenum)_blendState._colorDestBlend, 
                    (GLenum)_blendState._alphaSrcBlend, 
                    (GLenum)_blendState._alphaDestBlend
                );
        }

        if (forceUpdate || _blendState._blendFactor != _blendStateOld._blendFactor)
        {
            auto v = _blendState._blendFactor.ToVector4();
            glBlendColor(v.X, v.Y, v.Z, v.W);
        }

        if (forceUpdate || _blendState._multiSampleMask != _blendStateOld._multiSampleMask)
            glSampleMaski(0, BitCast<ui32>(_blendState._multiSampleMask));
        
        if (forceUpdate || _blendState._cwc0 != _blendStateOld._cwc0)
            glColorMaski(
                0,
                (GLboolean)(_blendState._cwc0 & ColorWriteChannels::Red),
                (GLboolean)(_blendState._cwc0 & ColorWriteChannels::Green),
                (GLboolean)(_blendState._cwc0 & ColorWriteChannels::Blue),
                (GLboolean)(_blendState._cwc0 & ColorWriteChannels::Alpha)
            );

        if (forceUpdate || _blendState._cwc1 != _blendStateOld._cwc1)
            glColorMaski(
                1,
                (GLboolean)(_blendState._cwc1 & ColorWriteChannels::Red),
                (GLboolean)(_blendState._cwc1 & ColorWriteChannels::Green),
                (GLboolean)(_blendState._cwc1 & ColorWriteChannels::Blue),
                (GLboolean)(_blendState._cwc1 & ColorWriteChannels::Alpha)
            );

        if (forceUpdate || _blendState._cwc2 != _blendStateOld._cwc2)
            glColorMaski(
                2,
                (GLboolean)(_blendState._cwc2 & ColorWriteChannels::Red),
                (GLboolean)(_blendState._cwc2 & ColorWriteChannels::Green),
                (GLboolean)(_blendState._cwc2 & ColorWriteChannels::Blue),
                (GLboolean)(_blendState._cwc2 & ColorWriteChannels::Alpha)
            );

        if (forceUpdate || _blendState._cwc3 != _blendStateOld._cwc3)
            glColorMaski(
                3,
                (GLboolean)(_blendState._cwc3 & ColorWriteChannels::Red),
                (GLboolean)(_blendState._cwc3 & ColorWriteChannels::Green),
                (GLboolean)(_blendState._cwc3 & ColorWriteChannels::Blue),
                (GLboolean)(_blendState._cwc3 & ColorWriteChannels::Alpha)
            );
#pragma endregion

    #pragma region RasterizerState
        if (forceUpdate || _rasterState._cullMode != _rasterStateOld._cullMode)
        {
            if (_rasterState._cullMode == CullMode::None)
                glDisable(GL_CULL_FACE);
            else if (_rasterStateOld._cullMode == CullMode::None)
                glEnable(GL_CULL_FACE);

            glFrontFace((GLenum)_rasterState._cullMode);
        }
         
        if (forceUpdate 
            || _rasterState._depthBias != _rasterStateOld._depthBias
            || _rasterState._slopeScaleDepthBias != _rasterStateOld._slopeScaleDepthBias)
        {
            if (_rasterState._depthBias == 0.0f && _rasterState._slopeScaleDepthBias == 0.0f)
                glDisable(GL_POLYGON_OFFSET_FILL);
            else if (_rasterStateOld._depthBias == 0.0f && _rasterStateOld._slopeScaleDepthBias == 0.0f)
                glEnable(GL_POLYGON_OFFSET_FILL);

            glPolygonOffset(_rasterState._slopeScaleDepthBias, _rasterState._depthBias);
        }

        if (forceUpdate || _rasterState._fillMode != _rasterStateOld._fillMode)
        {
            glPolygonMode(GL_FRONT_AND_BACK, (GLenum)_rasterState._fillMode);
        }

        if (forceUpdate || _rasterState._msaa != _rasterStateOld._msaa)
            if (_rasterState._msaa)
                glEnable(GL_MULTISAMPLE);
            else
                glDisable(GL_MULTISAMPLE);

        if (forceUpdate || _rasterState._scissorTest != _rasterStateOld._scissorTest)
            if (_rasterState._scissorTest)
                glEnable(GL_SCISSOR_TEST);
            else
                glDisable(GL_SCISSOR_TEST);


    #pragma endregion

    #pragma region DepthStencilState
    
        if (forceUpdate || _depthStencilState._depthBufferEnable != _depthStencilStateOld._depthBufferEnable)
            if (_depthStencilState._depthBufferEnable)
                glEnable(GL_DEPTH_TEST);
            else
                glDisable(GL_DEPTH_TEST);

        if (_depthStencilState._depthBufferEnable)
        {
            if (forceUpdate || _depthStencilState._depthBufferFunc != _depthStencilStateOld._depthBufferFunc)
                glDepthFunc((GLenum)_depthStencilState._depthBufferFunc);

            if (forceUpdate || _depthStencilState._depthBufferWriteEnable != _depthStencilStateOld._depthBufferWriteEnable)
                glDepthMask(_depthStencilState._depthBufferWriteEnable);
        }

        if (forceUpdate || _depthStencilState._stencilEnable != _depthStencilStateOld._stencilEnable)
            if (_depthStencilState._stencilEnable)
                glEnable(GL_STENCIL_TEST);
            else
                glDisable(GL_STENCIL_TEST);

        if (_depthStencilState._stencilEnable)
        {
            if (forceUpdate || _depthStencilState._stencilWriteMask != _depthStencilStateOld._stencilWriteMask)
                glStencilMask(_depthStencilState._stencilMask);

            if (_depthStencilState._twoSidedStencilMode)
            {
                if (forceUpdate || _depthStencilState._stencilFunc != _depthStencilStateOld._stencilFunc)
                    glStencilFuncSeparate(
                        GL_FRONT,
                        (GLenum)_depthStencilState._stencilFunc,
                        _depthStencilState._refStencil,
                        _depthStencilState._stencilMask
                    );

                if (forceUpdate || _depthStencilState._ccwStencilFunc != _depthStencilStateOld._ccwStencilFunc)
                    glStencilFuncSeparate(
                        GL_BACK,
                        (GLenum)_depthStencilState._ccwStencilFunc,
                        _depthStencilState._refStencil,
                        _depthStencilState._stencilMask
                    );

                if (forceUpdate 
                    || _depthStencilState._stencilFail != _depthStencilStateOld._stencilFail
                    || _depthStencilState._stencilDepthBufferFail != _depthStencilStateOld._stencilDepthBufferFail
                    || _depthStencilState._stencilPass != _depthStencilStateOld._stencilPass)
                    glStencilOpSeparate(
                        GL_FRONT,
                        (GLenum)_depthStencilState._stencilFail,
                        (GLenum)_depthStencilState._stencilDepthBufferFail,
                        (GLenum)_depthStencilState._stencilPass
                    );

                if (forceUpdate 
                    || _depthStencilState._ccwStencilFail != _depthStencilStateOld._ccwStencilFail
                    || _depthStencilState._ccwStencilDepthBufferFail != _depthStencilStateOld._ccwStencilDepthBufferFail
                    || _depthStencilState._ccwStencilPass != _depthStencilStateOld._ccwStencilPass)
                    glStencilOpSeparate(
                        GL_BACK,
                        (GLenum)_depthStencilState._ccwStencilFail,
                        (GLenum)_depthStencilState._ccwStencilDepthBufferFail,
                        (GLenum)_depthStencilState._ccwStencilPass
                    );
            }
            else
            {
                if (forceUpdate || _depthStencilState._stencilFunc != _depthStencilStateOld._stencilFunc)
                    glStencilFunc(
                        (GLenum)_depthStencilState._stencilFunc,
                        _depthStencilState._refStencil,
                        _depthStencilState._stencilMask
                    );

                if (forceUpdate 
                    || _depthStencilState._stencilFail != _depthStencilStateOld._stencilFail
                    || _depthStencilState._stencilDepthBufferFail != _depthStencilStateOld._stencilDepthBufferFail
                    || _depthStencilState._stencilPass != _depthStencilStateOld._stencilPass)
                    glStencilOp(
                        (GLenum)_depthStencilState._stencilFail,
                        (GLenum)_depthStencilState._stencilDepthBufferFail,
                        (GLenum)_depthStencilState._stencilPass
                    );
            }
        }
    #pragma endregion

        if (_rasterState._scissorTest)
        {
            if (forceUpdate || _scissorRect != _scissorRectOld)
                glScissor(_scissorRect.X(), _scissorRect.Y(), _scissorRect.Width(), _scissorRect.Height());
        }

        if (forceUpdate || _viewport != _viewportOld)
        {
            glViewport(_viewport.X(), _viewport.Y(), _viewport.Width(), _viewport.Height());
        }

        _blendStateOld = _blendState;
        _depthStencilStateOld = _depthStencilState;
        _rasterStateOld = _rasterState;
    }

    void GraphicsDevice::UpdateVertexAttribs(const VertexDeclaration& vertDecl)
    {
        if (!_lastUsedDecl || (_lastUsedDecl && vertDecl != *_lastUsedDecl))  
        {
            auto elems = vertDecl.GetVertexElements();
            _lastUsedDecl = &vertDecl;

            for (ui32 i = 0; i < elems.size(); i++)
            {
                auto& e = elems[i];
                VertexElementFormat fmt = e.VertexElementFormat();

                glVertexAttribPointer(
                    i,
                    VertexFormatComponents[fmt],
                    (GLenum)fmt,
                    Normalized(fmt),
                    vertDecl.VertexStride(),
                    (GLvoid*)e.Offset()
                    );

                //If ARB_instanced_arrays is a thing, reset the divisor
                if (GLEW_ARB_instanced_arrays)
                {
                    //This is the single-buffer attrib method, so no instancing is happening here.
                    glVertexAttribDivisor(i, 0);
                }

                glEnableVertexAttribArray(i);

            }
        }
    }

    void GraphicsDevice::UpdateMultiBufferVertexAttribs(i32 baseVert)
    {
        //Create a reference for sanity
        auto& vb = *_vertexBuffers;

        for (i32 i = _vertexBuffers->size(); i >= 0; i--)
        {
            auto vertDecl = vb[i].VertexBuffer()->VertexDeclaration();
            auto elems = vertDecl.GetVertexElements();

            vb[i].Bind();
            
            for (ui32 j = 0; j < elems.size(); j++)
            {

                auto& e = elems[j];
                VertexElementFormat fmt = e.VertexElementFormat();

                glVertexAttribPointer(
                    j,
                    VertexFormatComponents[fmt],
                    (GLenum)fmt,
                    Normalized(fmt),
                    vertDecl.VertexStride(),
                    (GLvoid*)(vertDecl.VertexStride() * (vb[i].VertexOffset() + baseVert) + e.Offset())
                );

                //If ARB_instanced_arrays is a thing, reset the divisor
                if (GLEW_ARB_instanced_arrays)
                {
                    //This is the multi-buffer attrib method, so set up the divisor in case instancing is happening
                    glVertexAttribDivisor(j, vb[i].InstanceFrequency());
                }

                glEnableVertexAttribArray(j);
            }
        }
    }

    void GraphicsDevice::DrawIndexedPrimitives(PrimitiveType pt, i32 baseVertex, i32 minVertIdx, i32 numVerts, i32 startIdx, i32 primCount)
    {
        if (!_indices || (_vertexBuffers && _vertexBuffers->size() == 0))
            throw std::runtime_error("A valid vertex buffer and a valid index buffer must be set.");

        i32 prog;
        glGetIntegerv(GL_CURRENT_PROGRAM, &prog);
        if (prog == 0)
            throw std::runtime_error("An effect must be applied before attempting to draw.");

        UpdateState();
        UpdateMultiBufferVertexAttribs(baseVertex);
        glDrawRangeElementsBaseVertex(
            (GLenum)pt,
            minVertIdx,
            minVertIdx + numVerts - 1,
            CalcPrimTypeVertices(pt, primCount),
            (GLenum)_indices->IndexElementSize(),
            (const void*)startIdx,
            baseVertex
        );
    }

    void GraphicsDevice::DrawInstancedPrimitives(PrimitiveType pt, i32 baseVertex, i32 minVertIdx, i32 numVerts, i32 startIdx, i32 primCount, i32 instCount)
    {
        if (!GLEW_ARB_instanced_arrays)
            throw std::runtime_error("This platform's OpenGL version does not support instanced rendering.");

        if (!_indices || (_vertexBuffers && _vertexBuffers->size() == 0))
            throw std::runtime_error("A valid vertex buffer and a valid index buffer must be set.");

        i32 prog;
        glGetIntegerv(GL_CURRENT_PROGRAM, &prog);
        if (prog == 0)
            throw std::runtime_error("An effect must be applied before attempting to draw.");

        UpdateState();
        UpdateMultiBufferVertexAttribs(baseVertex);
        glDrawElementsInstanced(
            (GLenum)pt,
            CalcPrimTypeVertices(pt, primCount),
            (GLenum)_indices->IndexElementSize(),
            (const void*)(startIdx * (_indices->IndexElementSize() == IndexElementSize::SixteenBits ? 2 : 4)),
            instCount
        );

    }

    void GraphicsDevice::DrawPrimitives(PrimitiveType pt, i32 startVert, i32 primCount)
    {
        if (_vertexBuffers && _vertexBuffers->size() == 0)
            throw std::runtime_error("A valid vertex buffer must be set.");

        i32 prog;
        glGetIntegerv(GL_CURRENT_PROGRAM, &prog);
        if (prog == 0)
            throw std::runtime_error("An effect must be applied before attempting to draw.");

        UpdateState();
        UpdateMultiBufferVertexAttribs(0);
        glDrawArrays((GLenum)pt, startVert, primCount);
    }

    void GraphicsDevice::Present() const
    {
        glfwPollEvents();
        glfwSwapBuffers(_presParams.DeviceWindowHandle());
    }

    
}