#ifndef FILL_MODE
#define FILL_MODE

#include "../GL/glew.h"

namespace XNA
{
	enum FillMode : short
	{
		Solid = GL_FILL,
		WireFrame = GL_LINE
	};
}

#endif