#ifndef _INDEX_ELEMENT_SIZE_H
#define _INDEX_ELEMENT_SIZE_H

#include "../../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class IndexElementSize : int 
	{
		EightBits = sizeof(GLubyte),
		SixteenBits = sizeof(GLushort),
		ThirtyTwoBits = sizeof(GLuint),
	};
}


#endif