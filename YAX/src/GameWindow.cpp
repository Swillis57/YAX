#include "../include/GameWindow.h"

#include "../include/Rectangle.h"
#include "../../external/glfw/include/GLFW/glfw3.h"

namespace YAX
{
	GameWindow::GameWindow(std::string t, i32 w, i32 h)
		: _title(t), _width(w), _height(h)
	{
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

		_handle = glfwCreateWindow(w, h, t.c_str(), NULL, NULL);
		glfwMakeContextCurrent(_handle);
	}

	GameWindow::~GameWindow()
	{
		glfwDestroyWindow(_handle);
	}

	bool GameWindow::AllowUserResizing() const
	{
		return _userCanResize;
	}

	void GameWindow::AllowUserResizing(bool b)
	{
		//Nothing changed, so don't touch anything
		if (_userCanResize == b) return;

		//Otherwise, set the appropriate window hint
		//Everything else is saved from the initial window creation
		_userCanResize = b;
		glfwWindowHint(GLFW_RESIZABLE, b);

		//Create a new window and share the context with it, destroy the current window,
		//and reassign the pointer
		GLFWmonitor* mon = glfwGetWindowMonitor(_handle);
		GLFWwindow* win = glfwCreateWindow(_width, _height, _title.c_str(), mon, _handle);
		glfwDestroyWindow(_handle);
		_handle = win;
	}

	void GameWindow::BeginScreenDeviceChange(bool fullScreen)
	{
		glfwWindowHint(GLFW_RESIZABLE, _userCanResize);
		_goingFullscreen = fullScreen;
	}

	void GameWindow::EndScreenDeviceChange(i32 monitor)
	{
		if (!_goingFullscreen) return;

		GLFWmonitor* dest = NULL;

		int numMonitors = 0;
		GLFWmonitor** monitors = glfwGetMonitors(&numMonitors);

		//If the provided monitor idx isn't valid, use the default one.
		if (monitor < 0 || monitor > numMonitors)
			dest = glfwGetPrimaryMonitor();
		else
			dest = monitors[monitor];

		GLFWwindow* win = glfwCreateWindow(_width, _height, _title.c_str(), dest, _handle);
		glfwDestroyWindow(_handle);
		_handle = win;
	}

	void GameWindow::EndScreenDeviceChange(i32 monitor, i32 w, i32 h)
	{
		_width = w;
		_height = h;
		EndScreenDeviceChange(monitor);
	}

	Rectangle GameWindow::ClientBounds() const
	{
		return Rectangle(0, 0, _width, _height);
	}

	GLFWwindow* GameWindow::Handle()
	{
		return _handle;
	}

	std::string GameWindow::ScreenDeviceName() const
	{
		return std::string("NYI");
	}

	std::string GameWindow::Title() const
	{
		return _title;
	}
	
	void GameWindow::Title(std::string s)
	{
		_title = s;
		glfwSetWindowTitle(_handle, _title.c_str());
	}
}