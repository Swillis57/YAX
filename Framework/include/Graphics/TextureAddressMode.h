#ifndef _TEXTURE_ADDRESS_MODE_H
#define _TEXTURE_ADDRESS_MODE_H

#include "../GLEW/glew.h"

namespace XNA
{
	enum class TextureAddressMode
	{
		Clamp = GL_CLAMP_TO_EDGE,
		Mirror = GL_MIRRORED_REPEAT,
		Wrap = GL_WRAP_BORDER
	};
}


#endif