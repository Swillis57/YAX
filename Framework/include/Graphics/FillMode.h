#ifndef _FILL_MODE_H
#define _FILL_MODE_H

#include "../GL/glew.h"

namespace XNA
{
	enum class FillMode
	{
		Solid = GL_FILL,
		WireFrame = GL_LINE
	};
}

#endif