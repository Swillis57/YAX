#ifndef _CULL_MODE_H
#define _CULL_MODE_H

#include "../../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class CullMode : int 
	{
		CullClockwiseFace = GL_CW,
		CullCounterClockwiseFace = GL_CCW,
		None
	};
}


#endif