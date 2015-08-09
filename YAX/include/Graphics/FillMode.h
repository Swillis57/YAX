#ifndef _FILL_MODE_H
#define _FILL_MODE_H

#include "../../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class FillMode : GLenum
	{
		Solid = GL_FILL,
		WireFrame = GL_LINE
	};
}

#endif