#ifndef _GAME_WINDOW_H
#define _GAME_WINDOW_H

#include <string>

struct GLFWwindow;

namespace XNA
{
	enum DisplayOrientation : short;

	class Rectangle;

	class GameWindow
	{
	public:
		bool AllowUserResizing();
		void AllowUserResizing(bool);

		Rectangle ClientBounds();

		DisplayOrientation CurrentOrientation();

		GLFWwindow* Handle();

		std::string ScreenDeviceName();

		std::string Title();
		void Title(std::string);	   

	protected:
		void OnActivated();
		void OnClientSizeChanged();
		void OnDeactivated();
		void OnOrientationChanged();
		void OnScreenDeviceNameChanged();
		void SetSupportedOrientations();
		void SetTitle();
	};
}


#endif