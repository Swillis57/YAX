#ifndef _GRAPHICS_DEVICE_H
#define _GRAPHICS_DEVICE_H

#include <array>
#include <memory>
#include <type_traits>
#include <vector>

#include "BlendState.h"
#include "DepthStencilState.h"
#include "DisplayMode.h"
#include "PresentationParameters.h"
#include "RasterizerState.h"	
#include "RenderTargetBinding.h"
#include "SamplerStateCollection.h"
#include "TextureCollection.h"
#include "VertexBufferBinding.h"
#include "VertexDeclaration.h"
#include "Viewport.h"
#include "../Utils.h"
#include "../Color.h"
#include "../Rectangle.h"

struct GLFWwindow;

namespace YAX
{ 
    enum class GraphicsProfile : ui32;
    enum class PrimitiveType : ui32;
    enum class ClearOptions : ui32;
    enum class RenderTargetUsage : ui32;

    class GameWindow;
    class GraphicsAdapter;
    class IndexBuffer;
    class RenderTarget2D;
    class RenderTargetCube;
    struct Vector4;
    class VertexDeclaration;
    class VertexBuffer;

    class GraphicsDevice
    {
        friend class GraphicsDeviceManager;

    public:
        #pragma region Properties
        GraphicsDevice(GraphicsAdapter&, GraphicsProfile, const YAX::PresentationParameters&);

        const GraphicsAdapter* Adapter() const;

        Color BlendFactor() const;
        void BlendFactor(Color);

        YAX::BlendState* BlendState();
        void BlendState(const YAX::BlendState&);

        YAX::DepthStencilState* DepthStencilState();
        void DepthStencilState(const YAX::DepthStencilState&);
                
        YAX::DisplayMode DisplayMode() const;

        YAX::GraphicsProfile GraphicsProfile() const;

        IndexBuffer* Indicies();
        void Indicies(IndexBuffer&);

        i32 MultiSampleMask() const;
        void MultiSampleMask(i32);

        YAX::PresentationParameters& PresentationParameters();

        YAX::RasterizerState RasterizerState() const;
        void RasterizerState(const YAX::RasterizerState&);

        i32 ReferenceStencil() const;
        void ReferenceStencil(i32);

        Rectangle ScissorRectangle() const;
        void ScissorRectangle(Rectangle);

        SamplerStateCollection& Samplers();

        TextureCollection& Textures();

        YAX::Viewport Viewport() const;
        void Viewport(YAX::Viewport);
#pragma endregion

        void Clear(const Color& clearColor) const;
        void Clear(ClearOptions options, const Color& clearColor, float depthVal, i32 stencilVal) const;
        void Clear(ClearOptions options, const Vector4& clearColor, float depthVal, i32 stencilVal) const;
        
        void DrawIndexedPrimitives(PrimitiveType, i32 baseVertex, i32 minVertIdx, i32 numVerts, i32 startIdx, i32 primCount);
        void DrawInstancedPrimitives(PrimitiveType, i32 baseVertex, i32 minVertIdx, i32 numVerts, i32 startIdx, i32 primCount, i32 instCount);
        void DrawPrimitives(PrimitiveType, i32 startVert, i32 primCount);
        
    private: //The templated Draw functions need to see these declarations
        void UpdateVertexAttribs(const VertexDeclaration&);
        void UpdateMultiBufferVertexAttribs(i32 baseVert);
        void UpdateState(bool = false);

    public:
        template<typename T, typename = std::enable_if<std::is_base_of<IVertexType, T>::value>::type>
        void DrawUserIndexedPrimitives(PrimitiveType, const std::vector<T>& vertData, i32 vertOffset, i32 numVerts, const std::vector<i16>& idxData, i32 idxOffset, i32 primCount) const
        {
            
        }

        template<typename T>
        void DrawUserIndexedPrimitives(PrimitiveType, const std::vector<T>&, i32, i32, const std::vector<i16>&, i32, i32, const VertexDeclaration&) const;
        template<typename T>
        void DrawUserIndexedPrimitives(PrimitiveType, const std::vector<T>&, i32, i32, const std::vector<i32>&, i32, i32) const;
        template<typename T>
        void DrawUserIndexedPrimitives(PrimitiveType, const std::vector<T>&, i32, i32, const std::vector<i32>&, i32, i32, const VertexDeclaration&) const;

        template<typename T>
        void DrawUserPrimitives(PrimitiveType, std::vector<T>&, i32, i32) const;
        template<typename T>
        void DrawUserPrimitives(PrimitiveType, std::vector<T>&, i32, i32, const VertexDeclaration&) const;

        template<typename T>
        void GetBackBufferData(std::unique_ptr<Rectangle>, std::vector<T>&, i32, i32) const;
        template<typename T>
        void GetBackBufferData(std::vector<T>&) const;
        template<typename T>
        void GetBackBufferData(std::vector<T>&, i32, i32) const;
         
        std::vector<RenderTargetBinding>* GetRenderTargets() const;
        std::vector<VertexBufferBinding>* GetVertexBuffers() const;

        void Present() const;
        void Present(Rectangle*, Rectangle*, GLFWwindow*) const;

        void Reset() const;
        void Reset(const YAX::PresentationParameters&) const;
        void Reset(const YAX::PresentationParameters&, const GraphicsAdapter&) const;

        void SetRenderTarget(const RenderTarget2D&);
        void SetRenderTarget(const RenderTargetCube&, CubeMapFace);
        void SetRenderTargets(const std::vector<RenderTargetBinding>&);

        void SetVertexBuffer(const VertexBuffer&);
        void SetVertexBuffer(const VertexBuffer&, i32);
        void SetVertexBuffers(const std::vector<VertexBufferBinding>&);

    private:
        bool _vertBindingsChanged;
        GraphicsAdapter* _adapter;
        YAX::BlendState _blendStateOld, _blendState;
        YAX::DepthStencilState _depthStencilStateOld, _depthStencilState;
        YAX::DisplayMode _displayMode;
        YAX::GraphicsProfile _graphicsProfile;
        GLuint _vao;
        IndexBuffer* _indices;
        i32 _msMaskOld, _msMask, _refStencilOld, _refStencil;
        YAX::PresentationParameters _presParams;
        YAX::RasterizerState _rasterStateOld, _rasterState;
        RenderTargetBinding* _boundRenderTarget;
        std::vector<RenderTargetBinding>* _renderTargets;
        std::vector<VertexBufferBinding>* _vertexBuffers;
        Rectangle _scissorRectOld, _scissorRect;
        SamplerStateCollection _samplers;//, _vertSamplerStates; Is this distinction needed in OpenGL? 
        TextureCollection _textures;//, _vertTextures;           The standard requires support for at least 24 combined units
        const VertexDeclaration* _lastUsedDecl;
        YAX::Viewport _viewportOld, _viewport;

        void ApplyFullscreen(GameWindow*);
        i32 CalcPrimTypeVertices(PrimitiveType, i32);
    };
}
#endif