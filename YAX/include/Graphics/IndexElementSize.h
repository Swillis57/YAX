#ifndef _INDEX_ELEMENT_SIZE_H
#define _INDEX_ELEMENT_SIZE_H

#include "../../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class IndexElementSize : GLenum 
	{
		EightBits = GL_UNSIGNED_BYTE,
		SixteenBits = GL_UNSIGNED_SHORT,
		ThirtyTwoBits = GL_UNSIGNED_INT
	};
}


#endif