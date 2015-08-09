#ifndef _RENDER_TARGET_BINDING_H
#define _RENDER_TARGET_BINDING_H

#include "../Utils.h"

namespace YAX
{
    enum class CubeMapFace : ui32;

    class RenderTarget2D;
    class RenderTargetCube;

    struct RenderTargetBinding
    {
        RenderTargetBinding();
        RenderTargetBinding(RenderTarget2D&);
        RenderTargetBinding(const RenderTargetCube&, YAX::CubeMapFace);

        void Bind() const;
        YAX::CubeMapFace CubeMapFace() const;
        const RenderTarget2D* RenderTarget() const;

    private:
        RenderTarget2D* _target;
        YAX::CubeMapFace _face;
    };
}


#endif