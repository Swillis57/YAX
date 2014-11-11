#ifndef _RENDER_TARGET_BINDING_H
#define _RENDER_TARGET_BINDING_H


#include "RenderTarget2D.h"
#include "../Utils.h"

namespace XNA
{
	enum class CubeMapFace : int;

	class RenderTargetCube;

	struct RenderTargetBinding
	{
		RenderTargetBinding(RenderTarget2D);
		RenderTargetBinding(const RenderTargetCube&, XNA::CubeMapFace);

		XNA::CubeMapFace CubeMapFace() const;
		RenderTarget2D RenderTarget() const;

	private:
		RenderTarget2D _target;
		XNA::CubeMapFace _face;
	};
}


#endif