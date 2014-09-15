#ifndef PRIMITIVE_TYPE
#define PRIMITIVE_TYPE

#include "../GL/glew.h"

namespace XNA
{
	enum PrimitiveType : short
	{
		TriangleList = GL_TRIANGLES,
		TriangleStrip = GL_TRIANGLE_STRIP,
		LineList = GL_LINES,
		LineStrip = GL_LINE_STRIP,
	};
}



#endif