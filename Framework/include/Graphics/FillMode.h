#ifndef _FILL_MODE_H
#define _FILL_MODE_H

#include "../GLEW/glew.h"

namespace YAX
{
	enum class FillMode : int 
	{
		Solid = GL_FILL,
		WireFrame = GL_LINE
	};
}

#endif