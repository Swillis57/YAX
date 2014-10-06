#ifndef _DEPTH_STENCIL_STATE_H
#define _DEPTH_STENCIL_STATE_H

#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	enum CompareFunction : short;
	enum StencilOperation : short;

	class DepthStencilState : public GraphicsResource
	{
	public:
		DepthStencilState();

		StencilOperation CounterClockwiseStencilDepthBufferFail();
		void CounterClockwiseStencilDepthBufferFail(StencilOperation);

		StencilOperation CounterClockwiseStencilFail();
		void CounterClockwiseStencilFail(StencilOperation);

		StencilOperation CounterClockwiseStencilFunction();
		void CounterClockwiseStencilFunction(StencilOperation);

		StencilOperation CounterClockwiseStencilPass();
		void CounteClockwiseStencilPass(StencilOperation);

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
		StencilOperation _ccwStencilDepthBufferFail;
		StencilOperation _ccwStencilFail;
		CompareFunction _ccwStencilFunc;
		StencilOperation _ccwStencilPass;
		bool _depthBufferEnable;
		CompareFunction _depthBufferFunc;
		bool _depthBufferWriteEnable;
		i32 _refStencil;
		StencilOperation _stencilDepthBufferFail;
		bool _stencilEnable;
		StencilOperation _stencilFail;
		CompareFunction _stencilFunc;
		i32 _stencilMask;
		StencilOperation _stencilPass;
		bool _twoSidedStencilMode;

	};
}


#endif