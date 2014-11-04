#ifndef _CULL_MODE_H
#define _CULL_MODE_H

#include "../GLEW/glew.h"

namespace XNA
{
	enum class CullMode : int 
	{
		CullClockwiseFace = GL_CW,
		CullCounterClockwiseFace = GL_CCW,
		None
	};
}


#endif