#ifndef _RENDER_TARGET_2D_H
#define _RENDER_TARGET_2D_H


#include "Texture2D.h"
#include "../../Framework/include/Utils.h"

namespace YAX
{
	enum class SurfaceFormat : int;
	enum class DepthFormat : int;
	enum class RenderTargetUsage : int;

	class GraphicsDevice;

	class RenderTarget2D : public Texture2D
	{
	public:
		RenderTarget2D(YAX::GraphicsDevice&, i32, i32);
		RenderTarget2D(YAX::GraphicsDevice&, i32, i32, bool, SurfaceFormat, DepthFormat);
		RenderTarget2D(YAX::GraphicsDevice&, i32, i32, bool, SurfaceFormat, DepthFormat, i32, RenderTargetUsage);
		RenderTarget2D(const RenderTarget2D&) = delete;
		RenderTarget2D& operator=(const RenderTarget2D&) = delete;
		RenderTarget2D(RenderTarget2D&&);
		RenderTarget2D& operator=(RenderTarget2D&&);
		~RenderTarget2D();

		DepthFormat DepthStencilFormat() const;

		bool IsContentLost() const;

		i32 MultiSampleCount() const;

		YAX::RenderTargetUsage RenderTargetUsage() const;
		void RenderTargetUsage(YAX::RenderTargetUsage);

	private:
		YAX::GraphicsDevice& _device;
		i32  _msCount;
		bool _mipMap;
		SurfaceFormat _surfFmt;
		DepthFormat _depFmt;
		YAX::RenderTargetUsage _usage;
	};
}

#endif