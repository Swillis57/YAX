#ifndef TEXTURE_ADDRESS_MODE
#define TEXTURE_ADDRESS_MODE

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