#ifndef _INDEX_ELEMENT_SIZE_H
#define _INDEX_ELEMENT_SIZE_H

#include "../GLEW/glew.h"

namespace XNA
{
	enum class IndexElementSize : int 
	{
		EightBits = sizeof(GLubyte),
		SixteenBits = sizeof(GLushort),
		ThirtyTwoBits = sizeof(GLuint),
	};
}


#endif