#ifndef _INDEX_ELEMENT_SIZE_H
#define _INDEX_ELEMENT_SIZE_H

#include "../GL/glew.h"

namespace XNA
{
	enum IndexElementSize : int
	{
		EightBits = sizeof(GLubyte),
		SixteenBits = sizeof(GLushort),
		ThirtyTwoBits = sizeof(GLuint),
	};
}


#endif