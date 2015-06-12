#ifndef _DEPTH_FORMAT_H
#define _DEPTH_FORMAT_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
	enum class DepthFormat : ui32 
	{
		Depth16 = GL_DEPTH_COMPONENT16,
		Depth24 = GL_DEPTH_COMPONENT24,	
		Depth24Stencil8 = GL_DEPTH24_STENCIL8,
		None = 0
	};
}

#endif