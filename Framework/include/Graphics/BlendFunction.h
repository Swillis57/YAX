#ifndef _BLEND_FUNCTION_H
#define _BLEND_FUNCTION_H

#include "../GLEW/glew.h"

namespace XNA
{
	enum class BlendFunction
	{
		Add = GL_FUNC_ADD,
		Max = GL_MAX,
		Min = GL_MIN,
		ReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
		Subtract = GL_FUNC_SUBTRACT
	};
}


#endif