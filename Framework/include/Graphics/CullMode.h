#ifndef _CULL_MODE_H
#define _CULL_MODE_H

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