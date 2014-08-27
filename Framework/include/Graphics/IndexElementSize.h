#ifndef INDEX_ELEMENT_SIZE
#define INDEX_ELEMENT_SIZE

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