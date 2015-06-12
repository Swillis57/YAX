#ifndef _RASTERIZER_STATE_H
#define _RASTERIZER_STATE_H

#include "GraphicsResource.h"
#include "../Utils.h"

namespace YAX
{
	enum class CullMode : ui32;
	enum class FillMode : ui32;

	struct RasterizerState : public GraphicsResource
	{
		static const RasterizerState CullClockwise;
		static const RasterizerState CullCounterClockwise;
		static const RasterizerState CullNone;

		RasterizerState();
		~RasterizerState() = default;

		YAX::CullMode CullMode() const;
		void CullMode(YAX::CullMode);

		float DepthBias() const;
		void DepthBias(float);

		YAX::FillMode FillMode() const;
		void FillMode(YAX::FillMode);

		bool MultiSampleAntiAlias() const;
		void MultiSampleAntiAlias(bool);

		bool ScissorTestEnable() const;
		void ScissorTestEnable(bool);

		float SlopeScaleDepthBias() const;
		void SlopeScaleDepthBias(float);

	private:
		RasterizerState(YAX::CullMode cm, std::string name);

		YAX::CullMode _cullMode;
		float _depthBias, _slopeScaleDepthBias;
		YAX::FillMode _fillMode;
		bool _msaa, _scissorTest;

	};
}


#endif