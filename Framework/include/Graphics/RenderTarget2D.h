#ifndef _RENDER_TARGET_2D_H
#define _RENDER_TARGET_2D_H

#include "Texture2D.h"

namespace XNA
{
	enum SurfaceFormat; short;
	enum DepthFormat : short;
	enum RenderTargetUsage : short;

	class GraphicsDevice;

	class RenderTarget2D
	{
		RenderTarget2D(GraphicsDevice&, i32, i32);
		RenderTarget2D(GraphicsDevice&, i32, i32, bool, SurfaceFormat, DepthFormat);
		RenderTarget2D(GraphicsDevice&, i32, i32, bool, SurfaceFormat, DepthFormat, i32, RenderTargetUsage);

		DepthFormat DepthStencilFormat();

		bool IsContentLost();

		i32 MultiSampleCount();

		XNA::RenderTargetUsage RenderTargetUsage();

	private:
		GraphicsDevice& _device;
		i32 _height, _width, _msCount;
		bool _mipMap;
		SurfaceFormat _surfFmt;
		DepthFormat _depFmt;
		XNA::RenderTargetUsage _usage;
	};
}

#endif