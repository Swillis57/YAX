#ifndef _TEXTURE_ADDRESS_MODE_H
#define _TEXTURE_ADDRESS_MODE_H

#include "../GL/glew.h"

namespace XNA
{
	enum TextureAddressMode : short
	{
		Clamp = GL_CLAMP_TO_EDGE,
		Mirror = GL_MIRRORED_REPEAT,
		Wrap = GL_WRAP_BORDER
	};
}


#endif