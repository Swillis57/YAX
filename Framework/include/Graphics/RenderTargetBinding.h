#ifndef _RENDER_TARGET_BINDING_H
#define _RENDER_TARGET_BINDING_H


#include "RenderTarget2D.h"
#include "../Utils.h"

namespace XNA
{
	enum CubeMapFace : short;

	class RenderTargetCube;

	struct RenderTargetBinding
	{
		RenderTargetBinding(RenderTarget2D);
		RenderTargetBinding(const RenderTargetCube&, XNA::CubeMapFace);

		XNA::CubeMapFace CubeMapFace();
		RenderTarget2D RenderTarget();

	private:
		RenderTarget2D _target;
		XNA::CubeMapFace _face;
	};
}


#endif