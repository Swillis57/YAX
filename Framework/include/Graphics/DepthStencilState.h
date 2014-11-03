#ifndef _DEPTH_STENCIL_STATE_H
#define _DEPTH_STENCIL_STATE_H

#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	enum class CompareFunction;
	enum class StencilOperation;

	class DepthStencilState : public GraphicsResource
	{
	public:
		DepthStencilState();

		StencilOperation CounterClockwiseStencilDepthBufferFail() const;
		void CounterClockwiseStencilDepthBufferFail(StencilOperation);

		StencilOperation CounterClockwiseStencilFail() const;
		void CounterClockwiseStencilFail(StencilOperation);

		StencilOperation CounterClockwiseStencilFunction() const;
		void CounterClockwiseStencilFunction(StencilOperation);

		StencilOperation CounterClockwiseStencilPass() const;
		void CounteClockwiseStencilPass(StencilOperation);

		bool DepthBufferEnable() const;
		void DepthBufferEnable(bool);

		CompareFunction DepthBufferFunction() const;
		void DepthBufferFunction(CompareFunction);

		bool DepthBufferWriteEnable() const;
		void DepthBufferWriteEnable(bool);

		i32 ReferenceStencil() const;
		void ReferenceStencil(i32);

		StencilOperation StencilDepthBufferFail() const;
		void StencilDepthBufferFail(StencilOperation);

		bool StencilEnable() const;
		void StencilEnable(bool);

		StencilOperation StencilFail() const;
		void StencilFail(StencilOperation);

		CompareFunction StencilFunction() const;
		void StencilFunction(CompareFunction);

		i32 StencilMask() const;
		void StencilMask(i32);

		StencilOperation StencilPass() const;
		void StencilPass(StencilOperation);

		i32 StencilWriteMask() const;
		void StencilWriteMask(i32);

		bool TwoSidedStencilMode() const;
		void TwoSidedStencilMode(bool);

	private:
		StencilOperation _ccwStencilDepthBufferFail, _ccwStencilFail, _ccwStencilPass, 
						 _stencilDepthBufferFail, _stencilFail, _stencilPass;
		CompareFunction _ccwStencilFunc, _depthBufferFunc, _stencilFunc;
		bool _depthBufferEnable, _stencilEnable, _depthBufferWriteEnable, _twoSidedStencilMode;
		i32 _refStencil, _stencilMask;

	};
}


#endif