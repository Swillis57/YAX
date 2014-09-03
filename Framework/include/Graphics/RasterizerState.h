#ifndef RASTERIZER_STATE
#define RASTERIZER_STATE

#include "GraphicsResource.h"

namespace XNA
{
	enum CullMode : short;
	enum FillMode : short;

	struct RasterizerState : public GraphicsResource
	{
		RasterizerState();
		~RasterizerState();

		static const RasterizerState CullClockwise;
		static const RasterizerState CullCounterClockwise;
		static const RasterizerState CullNone;

		XNA::CullMode CullMode();
		void CullMode(XNA::CullMode);

		float DepthBias();
		void DepthBias(float);

		XNA::FillMode FillMode;
		void FillMode(XNA::FillMode);

		bool MultiSampleAntiAlias();
		void MultiSampleAntiAlias(bool);

		bool ScissorTestEnable();
		void ScissorTestEnable(bool);

		float SlopeScaleDepthBias();
		void SlopeScaleDepthBias(float);

	private:
		XNA::CullMode _cullMode;
		float _depthBias;
		XNA::FillMode _fillMode;
		bool _msaa;
		bool _scissorTest;
		float _slopeScale;

	};
}


#endif