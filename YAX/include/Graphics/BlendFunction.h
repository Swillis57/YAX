#ifndef _BLEND_FUNCTION_H
#define _BLEND_FUNCTION_H

#include "../../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class BlendFunction : GLenum
	{
		Add = GL_FUNC_ADD,
		Max = GL_MAX,
		Min = GL_MIN,
		ReverseSubtract = GL_FUNC_REVERSE_SUBTRACT,
		Subtract = GL_FUNC_SUBTRACT
	};
}


#endif