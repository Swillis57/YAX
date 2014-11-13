#ifndef _DEPTH_FORMAT_H
#define _DEPTH_FORMAT_H

#include "../GLEW/glew.h"

namespace YAX
{
	enum class DepthFormat : int 
	{
		Depth16 = GL_DEPTH_COMPONENT16,
		Depth24 = GL_DEPTH_COMPONENT24,	
		Depth24Stencil8 = GL_DEPTH24_STENCIL8,
		None = -1
	};
}

#endif