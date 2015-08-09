#ifndef _COMPARE_FUNCTION_H
#define _COMPARE_FUNCTION_H

#include "../../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class CompareFunction : GLenum 
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