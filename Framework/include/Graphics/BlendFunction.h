#ifndef BLEND_FUNCTION
#define BLEND_FUNCTION

#include "../GL/glew.h"

namespace XNA
{
    enum BlendFunction
	{
		Add = GL_FUNC_ADD,
		Max = GL_MAX,
		Min = GL_MIN,
		ReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
		Subtract = GL_FUNC_SUBTRACT
	};
}


#endif