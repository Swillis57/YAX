#ifndef _GAME_WINDOW_H
#define _GAME_WINDOW_H

#include <string>
#include "Utils.h"

struct GLFWwindow;

namespace YAX
{
	class Game;
	class GraphicsDeviceManager;
	class Rectangle;

	class GameWindow
	{
		friend class Game;

	public:
		~GameWindow();

		bool AllowUserResizing() const;
		void AllowUserResizing(bool);
		
		void BeginScreenDeviceChange(bool);
		void EndScreenDeviceChange(i32);
		void EndScreenDeviceChange(i32, i32, i32);

		Rectangle ClientBounds() const;

		GLFWwindow* Handle();

		std::string ScreenDeviceName() const;

		std::string Title() const;
		void Title(std::string);

	private:
		GameWindow(std::string, i32, i32);
		
		bool _userCanResize, _goingFullscreen;
		i32 _width, _height;
		GLFWwindow* _handle;
		std::string _title;
	};
}


#endif