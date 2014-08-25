#ifndef COMPARE_FUNCTION
#define COMPARE_FUNCTION

#include "../GL/glew.h"

namespace XNA
{
    enum CompareFunction
	{
		Always = GL_ALWAYS,
		Equal = GL_EQUAL,
		Greater = GL_GREATER,
		GreaterEqual = GL_GEQUAL,
		Less = GL_LESS,
		LessEqual = GL_LEQUAL,
		Never = GL_NEVER,
		NotEqual = GL_NOTEQUAL
	};
}


#endif