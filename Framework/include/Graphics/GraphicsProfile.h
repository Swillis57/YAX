#ifndef _GRAPHICS_PROFILE_H
#define _GRAPHICS_PROFILE_H

#include "../GLFW/glfw3.h"	

namespace YAX
{
	enum class GraphicsProfile : int 
	{			 
		HiDef = GLFW_OPENGL_CORE_PROFILE,
		Reach = GLFW_OPENGL_COMPAT_PROFILE,
	};
}
#endif