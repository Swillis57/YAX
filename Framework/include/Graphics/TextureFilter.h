#ifndef _TEXTURE_FILTER_H
#define _TEXTURE_FILTER_H

#include "../GLEW/glew.h"

namespace XNA
{
	enum class TextureFilter
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