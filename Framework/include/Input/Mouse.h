#ifndef _MOUSE_H
#define _MOUSE_H

#include "../Utils.h"

struct GLFWwindow;

namespace XNA
{
	class MouseState;

	class Mouse
	{
	public:
		static GLFWwindow* WindowHandle();
		static void WindowHandle(GLFWwindow*);

		static MouseState GetState();

		static void SetPosition(i32, i32);
	};
}


#endif