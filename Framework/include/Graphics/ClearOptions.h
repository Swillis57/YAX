#ifndef _CLEAR_OPTIONS_H
#define _CLEAR_OPTIONS_H

#include "../GLEW/glew.h"

namespace XNA
{
	enum class ClearOptions
	{
		DepthBuffer = GL_DEPTH_BUFFER_BIT,
		Stencil = GL_STENCIL_BUFFER_BIT,
		Target =  GL_COLOR_BUFFER_BIT
	};
}


#endif