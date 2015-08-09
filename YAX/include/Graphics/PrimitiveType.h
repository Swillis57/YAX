#ifndef _PRIMITIVE_TYPE_H
#define _PRIMITIVE_TYPE_H

#include "../../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class PrimitiveType : GLenum 
	{
		TriangleList = GL_TRIANGLES,
		TriangleStrip = GL_TRIANGLE_STRIP,
		LineList = GL_LINES,
		LineStrip = GL_LINE_STRIP,
	};
}



#endif