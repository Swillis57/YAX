#ifndef _COMPARE_FUNCTION_H
#define _COMPARE_FUNCTION_H

#include "../GL/glew.h"

namespace XNA
{
	enum CompareFunction : short
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