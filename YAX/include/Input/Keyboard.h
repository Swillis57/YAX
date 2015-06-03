#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <vector>

namespace YAX
{
	enum class PlayerIndex : int;
	enum class Keys : int;
	class KeyboardState;

	class Keyboard
	{
	public:
		static KeyboardState GetState();
		static KeyboardState GetState(PlayerIndex);

	private:
		static std::vector<bool> _keys;
	};
}


#endif