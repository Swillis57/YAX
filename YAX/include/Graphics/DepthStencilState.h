#ifndef _DEPTH_STENCIL_STATE_H
#define _DEPTH_STENCIL_STATE_H

#include "../Utils.h"

namespace YAX
{
    enum class CompareFunction : ui32;
    enum class StencilOperation : ui32;

    class DepthStencilState
    {
        friend class GraphicsDevice;

    public:
        static const DepthStencilState Default;
        static const DepthStencilState DepthRead;
        static const DepthStencilState None;

        DepthStencilState();
        DepthStencilState(bool, bool);
        ~DepthStencilState() = default;

        StencilOperation CounterClockwiseStencilDepthBufferFail();
        void CounterClockwiseStencilDepthBufferFail(StencilOperation);

        StencilOperation CounterClockwiseStencilFail();
        void CounterClockwiseStencilFail(StencilOperation);

        CompareFunction CounterClockwiseStencilFunction();
        void CounterClockwiseStencilFunction(CompareFunction);

        StencilOperation CounterClockwiseStencilPass();
        void CounterClockwiseStencilPass(StencilOperation);

        bool DepthBufferEnable();
        void DepthBufferEnable(bool);

        CompareFunction DepthBufferFunction();
        void DepthBufferFunction(CompareFunction);

        bool DepthBufferWriteEnable();
        void DepthBufferWriteEnable(bool);

        i32 ReferenceStencil();
        void ReferenceStencil(i32);

        StencilOperation StencilDepthBufferFail();
        void StencilDepthBufferFail(StencilOperation);

        bool StencilEnable();
        void StencilEnable(bool);

        StencilOperation StencilFail();
        void StencilFail(StencilOperation);

        CompareFunction StencilFunction();
        void StencilFunction(CompareFunction);

        i32 StencilMask();
        void StencilMask(i32);

        StencilOperation StencilPass();
        void StencilPass(StencilOperation);

        i32 StencilWriteMask();
        void StencilWriteMask(i32);

        bool TwoSidedStencilMode();
        void TwoSidedStencilMode(bool);

    private:
        StencilOperation _ccwStencilDepthBufferFail, _ccwStencilFail, _ccwStencilPass, 
                         _stencilDepthBufferFail, _stencilFail, _stencilPass;
        CompareFunction _ccwStencilFunc, _depthBufferFunc, _stencilFunc;
        bool _depthBufferEnable, _stencilEnable, _depthBufferWriteEnable, _twoSidedStencilMode;
        i32 _refStencil, _stencilMask, _stencilWriteMask;

    };
}


#endif