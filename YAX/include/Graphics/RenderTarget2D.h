#ifndef _RENDER_TARGET_2D_H
#define _RENDER_TARGET_2D_H

#include "Texture2D.h"
#include "../Utils.h"

namespace YAX
{
	enum class SurfaceFormat : ui32;
	enum class DepthFormat : ui32;
	enum class RenderTargetUsage : ui32;

	class GraphicsDevice;

	class RenderTarget2D : public Texture2D
	{
	public:
		RenderTarget2D(i32, i32);
		RenderTarget2D(i32, i32, bool, SurfaceFormat, DepthFormat);
		RenderTarget2D(i32, i32, bool, SurfaceFormat, DepthFormat, i32, RenderTargetUsage);
		RenderTarget2D(const RenderTarget2D&) = delete;
		RenderTarget2D& operator=(const RenderTarget2D&) = delete;
		RenderTarget2D(RenderTarget2D&&);
		RenderTarget2D& operator=(RenderTarget2D&&);
		~RenderTarget2D();

		DepthFormat DepthStencilFormat() const;

		i32 MultiSampleCount() const;

		YAX::RenderTargetUsage RenderTargetUsage() const;

	private:
		i32  _msCount;
		DepthFormat _depFmt;
		YAX::RenderTargetUsage _usage;
	};
}

#endif