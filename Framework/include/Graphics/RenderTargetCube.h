#ifndef _RENDER_TARGET_CUBE_H
#define _RENDER_TARGET_CUBE_H

#include "TextureCube.h"
#include "../Utils.h"


namespace XNA
{
	enum class SurfaceFormat : int;
	enum class DepthFormat : int;
	enum class RenderTargetUsage : int;

	class GraphicsDevice;

	class RenderTargetCube : public TextureCube
	{
		RenderTargetCube(XNA::GraphicsDevice&, i32, bool, SurfaceFormat, DepthFormat);
		RenderTargetCube(XNA::GraphicsDevice&, i32, bool, SurfaceFormat, DepthFormat, RenderTargetUsage);

		DepthFormat DepthStencilFormat();
		
		bool IsContextLost();

		i32 MultiSampleCount();

		XNA::RenderTargetUsage RenderTargetUsage();
	};
}


#endif