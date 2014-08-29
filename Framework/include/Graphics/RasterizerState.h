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



	};
}


#endif