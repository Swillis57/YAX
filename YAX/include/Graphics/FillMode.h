#ifndef _FILL_MODE_H
#define _FILL_MODE_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
	enum class FillMode : ui32
	{
		Solid = GL_FILL,
		WireFrame = GL_LINE
	};
}

#endif