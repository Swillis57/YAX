#ifndef _SURFACEFORMAT_H
#define _SURFACEFORMAT_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
    enum class SurfaceFormat : ui32 
    {
        Color = GL_RGBA8UI,
        Bgr565 = GL_RGB565,
        Bgr4444 = GL_RGBA4,
        Bgra5551 = GL_RGB5_A1,
        NormalizedByte2 = GL_RG8_SNORM,
        NormalizedByte4 = GL_RGBA8_SNORM,
        Rgba1010102 = GL_RGB10_A2,
        Rg32 = GL_RG16,
        Rgba64 = GL_RGBA16,
        Alpha8 = GL_R8,
        Single = GL_R32F,
        Vector2 = GL_RG32F,
        Vector4 = GL_RGBA32F,
        HalfSingle = GL_R16F,
        HalfVector2 = GL_RG16F,
        HalfVector4 = GL_RGBA16F
    };
}

#endif