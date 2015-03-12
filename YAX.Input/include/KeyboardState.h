#ifndef _KEYBOARD_STATE_H
#define _KEYBOARD_STATE_H

#include <bitset>
#include <vector>

#define NUM_SUPPORTED_KEYS 90

namespace YAX
{
	enum Keys;
	enum KeyState;

	struct KeyboardState
	{
		KeyboardState(const std::vector<Keys>&);

		std::vector<Keys> GetPressedKeys();

		bool IsKeyDown(Keys);
		
		bool IsKeyUp(Keys);


		friend bool operator==(const KeyboardState&, const KeyboardState&);
		friend bool operator!=(const KeyboardState&, const KeyboardState&);

		KeyState operator[](Keys);

	private:
		std::bitset<NUM_SUPPORTED_KEYS> _keys;
	};
}


#endif