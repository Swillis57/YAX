#ifndef DEPTH_FORMAT
#define DEPTH_FORMAT

#include "../GL/glew.h"

namespace XNA
{
	enum DepthFormat
	{
		Depth16 = GL_DEPTH_COMPONENT16,
		Depth24 = GL_DEPTH_COMPONENT24,
		Depth24Stencil8 = GL_DEPTH24_STENCIL8,
		None = -1
	};
}

#endif