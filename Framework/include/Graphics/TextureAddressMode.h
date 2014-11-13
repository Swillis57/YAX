#ifndef _TEXTURE_ADDRESS_MODE_H
#define _TEXTURE_ADDRESS_MODE_H

#include "../GLEW/glew.h"

namespace YAX
{
	enum class TextureAddressMode : int 
	{
		Clamp = GL_CLAMP_TO_EDGE,
		Mirror = GL_MIRRORED_REPEAT,
		Wrap = GL_WRAP_BORDER
	};
}


#endif