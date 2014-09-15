#ifndef TEXTURE_FILTER
#define TEXTURE_FILTER

#include "../GL/glew.h"

namespace XNA
{
	enum TextureFilter : short
	{
		Linear = GL_LINEAR,
		Point = GL_NEAREST,
		Anisotropic = GL_EXT_texture_filter_anisotropic,
		LinearMipPoint = GL_LINEAR_MIPMAP_NEAREST,
		PointMipLinear = GL_NEAREST_MIPMAP_LINEAR,
		MinLinearMagPointMipLinear = -1,
		MinLinearMagPointMipPoint = -2,
		MinPointMagLinearMipLinear = -3,
		MinPointMagLinearMipPoint = -4
	};
}



#endif