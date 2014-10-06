#ifndef _STENCIL_OPERATION_H
#define _STENCIL_OPERATION_H

#include "../GL/glew.h"

namespace XNA
{
	enum StencilOperation : short
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