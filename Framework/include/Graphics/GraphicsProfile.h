#ifndef _GRAPHICS_PROFILE_H
#define _GRAPHICS_PROFILE_H

#include "../GLFW/glfw3.h"
#include "../Utils.h"

namespace XNA
{
	enum class GraphicsProfile
	{			 
		HiDef = GLFW_OPENGL_API,
		Reach = GLFW_OPENGL_ES_API
	};
}
#endif