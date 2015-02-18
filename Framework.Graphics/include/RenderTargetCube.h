#ifndef _RENDER_TARGET_CUBE_H
#define _RENDER_TARGET_CUBE_H

#include "DepthFormat.h"
#include "RenderTargetUsage.h"
#include "TextureCube.h"
#include "../../Framework/include/Utils.h"


namespace YAX
{
	enum class SurfaceFormat : int;

	class GraphicsDevice;

	class RenderTargetCube : public TextureCube
	{
		RenderTargetCube(YAX::GraphicsDevice&, i32, bool, SurfaceFormat, DepthFormat);
		RenderTargetCube(YAX::GraphicsDevice&, i32, bool, SurfaceFormat, DepthFormat, RenderTargetUsage);
		RenderTargetCube(const RenderTargetCube&) = delete;
		RenderTargetCube& operator=(const RenderTargetCube&) = delete;
		RenderTargetCube(RenderTargetCube&&);
		RenderTargetCube& operator=(RenderTargetCube&&);


		DepthFormat DepthStencilFormat() const;
		
		bool IsContextLost() const;

		i32 MultiSampleCount() const;

		YAX::RenderTargetUsage RenderTargetUsage() const;
	
	private:
		DepthFormat _depthFmt;
		YAX::RenderTargetUsage _usage;
		i32 _msCount;
	};
}


#endif