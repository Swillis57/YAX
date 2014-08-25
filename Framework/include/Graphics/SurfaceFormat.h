#ifndef SURFACEFORMAT
#define SURFACEFORMAT

#include "../GL/glew.h"


namespace XNA
{
    enum SurfaceFormat
	{
		Color = GL_RGBA8UI,
		Rgb565 = GL_RGB565,
		Rgba4444 = GL_RGBA4,
		Bgr565 = GL_BGR,
		Bgr4444 = GL_BGRA,
		Bgra5551 = GL_BGRA,
		NormalizedByte2 = GL_RG8_SNORM,
		NormalizedByte4 = GL_RGBA8_SNORM,
		Rgba1010102 = GL_RGB10_A2UI,
		Rg32 = GL_RG16UI,
		Rgba64 = GL_RGBA16UI,
		Alpha8 = GL_R8,
		Single = GL_R32F,
		Vector2 = GL_RG32F,
		Vector4 = GL_RGBA32F,
		HalfSingle = GL_R16F,
		HalfVector2 = GL_RG16F,
		HalfVector4 = GL_RGBA16F,
	};
}

#endif