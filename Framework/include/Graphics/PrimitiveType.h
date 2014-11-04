#ifndef _PRIMITIVE_TYPE_H
#define _PRIMITIVE_TYPE_H

#include "../GLEW/glew.h"

namespace XNA
{
	enum class PrimitiveType : int 
	{
		TriangleList = GL_TRIANGLES,
		TriangleStrip = GL_TRIANGLE_STRIP,
		LineList = GL_LINES,
		LineStrip = GL_LINE_STRIP,
	};
}



#endif