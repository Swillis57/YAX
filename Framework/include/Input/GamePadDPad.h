#ifndef _GAME_PAD_DPAD_H
#define _GAME_PAD_DPAD_H

namespace XNA
{
	enum ButtonState : short;

	struct GamePadDPad
	{
	public:
		GamePadDPad(ButtonState, ButtonState, ButtonState, ButtonState);

		ButtonState Down();

		ButtonState Left();

		ButtonState Right();

		ButtonState Up();

		friend bool operator==(const GamePadDPad&, const GamePadDPad&);
		friend bool operator!=(const GamePadDPad&, const GamePadDPad&);
	
	private:
		ButtonState _buttons;
	};
}

#endif

