#ifndef _GRAPHICS_PROFILE_H
#define _GRAPHICS_PROFILE_H

#include "../GLFW/glfw3.h"

namespace XNA
{
	enum GraphicsProfile : short
	{			 
		HiDef = GLFW_OPENGL_API,
		Reach = GLFW_OPENGL_ES_API
	};
}
#endif