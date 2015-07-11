#ifndef _TEXTURE_FILTER_H
#define _TEXTURE_FILTER_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
	enum class TextureFilter : ui32 
	{
		Linear = GL_LINEAR,
		Point = GL_NEAREST,
		Anisotropic = GL_EXT_texture_filter_anisotropic,
		LinearMipPoint = GL_LINEAR_MIPMAP_NEAREST,
		PointMipLinear = GL_NEAREST_MIPMAP_LINEAR,
		//OpenGL doesn't have any enums to represent these
		//MinLinearMagPointMipLinear = -1,
		//MinLinearMagPointMipPoint = -2,
		//MinPointMagLinearMipLinear = -3,
		//MinPointMagLinearMipPoint = -4
	};
}



#endif