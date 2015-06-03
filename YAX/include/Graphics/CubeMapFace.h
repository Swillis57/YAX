#ifndef _CUBE_MAP_FACE_H
#define _CUBE_MAP_FACE_H

#include "../../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class CubeMapFace : int 
	{
		NegativeX = GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
		NegativeY = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
		NegativeZ = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
		PositiveX = GL_TEXTURE_CUBE_MAP_POSITIVE_X,
		PositiveY = GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
		PositiveZ = GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	};
}



#endif