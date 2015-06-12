#ifndef _CULL_MODE_H
#define _CULL_MODE_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
	enum class CullMode : ui32 
	{
		CullClockwiseFace = GL_CW,
		CullCounterClockwiseFace = GL_CCW,
		None
	};
}


#endif