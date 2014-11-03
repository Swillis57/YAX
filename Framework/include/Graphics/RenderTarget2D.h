#ifndef _RENDER_TARGET_2D_H
#define _RENDER_TARGET_2D_H


#include "Texture2D.h"
#include "../Utils.h"

namespace XNA
{
	enum class SurfaceFormat : int;
	enum class DepthFormat : int;
	enum class RenderTargetUsage : int;

	class GraphicsDevice;

	class RenderTarget2D : public Texture2D
	{
	public:
		RenderTarget2D(XNA::GraphicsDevice&, i32, i32);
		RenderTarget2D(XNA::GraphicsDevice&, i32, i32, bool, SurfaceFormat, DepthFormat);
		RenderTarget2D(XNA::GraphicsDevice&, i32, i32, bool, SurfaceFormat, DepthFormat, i32, RenderTargetUsage);

		DepthFormat DepthStencilFormat();

		bool IsContentLost();

		i32 MultiSampleCount();

		XNA::RenderTargetUsage RenderTargetUsage();

	private:
		XNA::GraphicsDevice& _device;
		i32 _height, _width, _msCount;
		bool _mipMap;
		SurfaceFormat _surfFmt;
		DepthFormat _depFmt;
		XNA::RenderTargetUsage _usage;
	};
}

#endif