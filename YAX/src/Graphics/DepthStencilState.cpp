#include "Graphics/DepthStencilState.h"

#include "Graphics/CompareFunction.h"
#include "Graphics/StencilOperation.h"

namespace YAX
{
    const DepthStencilState DepthStencilState::Default = DepthStencilState(true, true);
    const DepthStencilState DepthStencilState::DepthRead = DepthStencilState(true, false);
    const DepthStencilState DepthStencilState::None = DepthStencilState(false, false);

    DepthStencilState::DepthStencilState()
        : DepthStencilState(true, true)
    {}

    DepthStencilState::DepthStencilState(bool bufEnable = true, bool bufWriteEnable = true)
        : _ccwStencilDepthBufferFail(StencilOperation::Keep),
        _ccwStencilFail(StencilOperation::Keep),
        _ccwStencilFunc(CompareFunction::Always),
        _ccwStencilPass(StencilOperation::Keep),
        _depthBufferEnable(bufEnable),
        _depthBufferFunc(CompareFunction::LessEqual),
        _depthBufferWriteEnable(bufWriteEnable),
        _refStencil(0),
        _stencilDepthBufferFail(StencilOperation::Keep),
        _stencilEnable(false),
        _stencilFail(StencilOperation::Keep),
        _stencilFunc(CompareFunction::Always),
        _stencilMask(0x7FFFFFFF),
        _stencilPass(StencilOperation::Keep),
        _stencilWriteMask(0x7FFFFFFF),
        _twoSidedStencilMode(false)
    {}

    StencilOperation DepthStencilState::CounterClockwiseStencilDepthBufferFail()
    {
        return _ccwStencilDepthBufferFail;
    }

    void DepthStencilState::CounterClockwiseStencilDepthBufferFail(StencilOperation s)
    {
        _ccwStencilDepthBufferFail = s;
    }

    StencilOperation DepthStencilState::CounterClockwiseStencilFail()
    {
        return _ccwStencilFail;
    }

    void DepthStencilState::CounterClockwiseStencilFail(StencilOperation s)
    {
        _ccwStencilFail = s;
    }

    CompareFunction DepthStencilState::CounterClockwiseStencilFunction()
    {
        return _ccwStencilFunc;
    }

    void DepthStencilState::CounterClockwiseStencilFunction(CompareFunction c)
    {
        _ccwStencilFunc = c;
    }

    StencilOperation DepthStencilState::CounterClockwiseStencilPass()
    {
        return _ccwStencilPass;
    }

    void DepthStencilState::CounterClockwiseStencilPass(StencilOperation s)
    {
        _ccwStencilPass = s;
    }

    bool DepthStencilState::DepthBufferEnable()
    {
        return _depthBufferEnable;
    }

    void DepthStencilState::DepthBufferEnable(bool b)
    {
        _depthBufferEnable = b;
    }

    CompareFunction DepthStencilState::DepthBufferFunction()
    {
        return _depthBufferFunc;
    }

    void DepthStencilState::DepthBufferFunction(CompareFunction c)
    {
        _depthBufferFunc = c;
    }

    bool DepthStencilState::DepthBufferWriteEnable()
    {
        return _depthBufferWriteEnable;
    }

    void DepthStencilState::DepthBufferWriteEnable(bool b)
    {
        _depthBufferWriteEnable = b;
    }

    i32 DepthStencilState::ReferenceStencil()
    {
        return _refStencil;
    }

    void DepthStencilState::ReferenceStencil(i32 i)
    {
        _refStencil = i;
    }

    StencilOperation DepthStencilState::StencilDepthBufferFail()
    {
        return _stencilDepthBufferFail;
    }

    void DepthStencilState::StencilDepthBufferFail(StencilOperation s)
    {
        _stencilDepthBufferFail = s;
    }

    bool DepthStencilState::StencilEnable()
    {
        return _stencilEnable;
    }

    void DepthStencilState::StencilEnable(bool b)
    {
        _stencilEnable = b;
    }

    StencilOperation DepthStencilState::StencilFail()
    {
        return _stencilFail;
    }

    void DepthStencilState::StencilFail(StencilOperation s)
    {
        _stencilFail = s;
    }

    CompareFunction DepthStencilState::StencilFunction()
    {
        return _stencilFunc;
    }

    void DepthStencilState::StencilFunction(CompareFunction c)
    {
        _stencilFunc = c;
    }

    i32 DepthStencilState::StencilMask()
    {
        return _stencilMask;
    }

    void DepthStencilState::StencilMask(i32 mask)
    {
        _stencilMask = mask;
    }

    StencilOperation DepthStencilState::StencilPass()
    {
        return _stencilPass;
    }

    void DepthStencilState::StencilPass(StencilOperation s)
    {
        _stencilPass = s;
    }

    i32 DepthStencilState::StencilWriteMask()
    {
        return _stencilWriteMask;
    }

    void DepthStencilState::StencilWriteMask(i32 mask)
    {
        _stencilWriteMask = mask;
    }

    bool DepthStencilState::TwoSidedStencilMode()
    {
        return _twoSidedStencilMode;
    }

    void DepthStencilState::TwoSidedStencilMode(bool b)
    {
        _twoSidedStencilMode = b;
    }

}