#ifndef CLEAR_OPTIONS
#define CLEAR_OPTIONS

#include "../GL/glew.h"

namespace XNA
{
	enum ClearOptions : short
	{
		DepthBuffer = GL_DEPTH_BUFFER_BIT,
		Stencil = GL_STENCIL_BUFFER_BIT,
		Target =  GL_COLOR_BUFFER_BIT
	};
}


#endif