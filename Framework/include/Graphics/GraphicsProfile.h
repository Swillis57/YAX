#ifndef GRAPHICS_PROFILE
#define GRAPHICS_PROFILE

#include "../GLFW/glfw3.h"

namespace XNA
{
	enum GraphicsProfile
	{			 
		HiDef = GLFW_OPENGL_API,
		Reach = GLFW_OPENGL_ES_API
	};
}
#endif