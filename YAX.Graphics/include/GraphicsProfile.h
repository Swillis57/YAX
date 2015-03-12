#ifndef _GRAPHICS_PROFILE_H
#define _GRAPHICS_PROFILE_H

#include "../../external/glfw/include/GLFW/glfw3.h"

namespace YAX
{
	//Only targeting PC for now, so GraphicsProfile represents
	//the core and compatibility profile selection
	enum class GraphicsProfile : int 
	{			 
		HiDef = GLFW_OPENGL_CORE_PROFILE,
		Reach = GLFW_OPENGL_COMPAT_PROFILE,
	};
}
#endif