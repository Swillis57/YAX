#ifndef _RASTERIZER_STATE_H
#define _RASTERIZER_STATE_H

#include "GraphicsResource.h"

namespace XNA
{
	enum class CullMode : int;
	enum class FillMode : int;

	struct RasterizerState : public GraphicsResource
	{
		static const RasterizerState CullClockwise;
		static const RasterizerState CullCounterClockwise;
		static const RasterizerState CullNone;

		RasterizerState();

		XNA::CullMode CullMode() const;
		void CullMode(XNA::CullMode);

		float DepthBias() const;
		void DepthBias(float);

		XNA::FillMode FillMode() const;
		void FillMode(XNA::FillMode);

		bool MultiSampleAntiAlias() const;
		void MultiSampleAntiAlias(bool);

		bool ScissorTestEnable() const;
		void ScissorTestEnable(bool);

		float SlopeScaleDepthBias() const;
		void SlopeScaleDepthBias(float);

	private:
		XNA::CullMode _cullMode;
		float _depthBias, _slopeScale;
		XNA::FillMode _fillMode;
		bool _msaa, _scissorTest;

	};
}


#endif