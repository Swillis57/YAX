#ifndef _RENDER_TARGET_BINDING_H
#define _RENDER_TARGET_BINDING_H


#include "RenderTarget2D.h"
#include "../../Framework/include/Utils.h"

namespace YAX
{
	enum class CubeMapFace : int;

	class RenderTargetCube;

	struct RenderTargetBinding
	{
		RenderTargetBinding(RenderTarget2D&);
		RenderTargetBinding(const RenderTargetCube&, YAX::CubeMapFace);

		YAX::CubeMapFace CubeMapFace() const;
		RenderTarget2D RenderTarget() const;

	private:
		RenderTarget2D& _target;
		YAX::CubeMapFace _face;
	};
}


#endif