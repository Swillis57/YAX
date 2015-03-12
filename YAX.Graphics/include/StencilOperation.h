#ifndef _STENCIL_OPERATION_H
#define _STENCIL_OPERATION_H

#include "../../external/glew/include/GL/glew.h"

namespace YAX
{
	enum class StencilOperation : int 
	{
		Decrement = GL_DECR_WRAP,
		DecrementSaturation = GL_DECR,
		Increment = GL_INCR_WRAP,
		IncrementSaturation = GL_INCR,
		Invert = GL_INVERT,
		Keep = GL_KEEP,
		Replace = GL_REPLACE, 
		Zero = GL_ZERO
	};
}


#endif