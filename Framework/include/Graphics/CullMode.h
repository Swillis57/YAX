#ifndef CULL_MODE
#define CULL_MODE

#include "../GL/glew.h"

namespace XNA
{
	enum CullMode : short
	{
		CullClockwiseFace = GL_CW,
		CullCounterClockwiseFace = GL_CCW,
		None
	};
}


#endif