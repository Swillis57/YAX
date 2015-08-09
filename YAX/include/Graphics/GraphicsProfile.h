#ifndef _GRAPHICS_PROFILE_H
#define _GRAPHICS_PROFILE_H

#include "../../../external/glfw/include/GLFW/glfw3.h"
#include "../Utils.h"

namespace YAX
{
	//Only targeting PC for now, so GraphicsProfile represents
	//the core and compatibility profile selection
	enum class GraphicsProfile : ui32
	{			 
		HiDef = GLFW_OPENGL_CORE_PROFILE,
		Reach = GLFW_OPENGL_COMPAT_PROFILE,
	};
}
#endif