#ifndef _GAME_PAD_BUTTONS_H
#define _GAME_PAD_BUTTONS_H

namespace YAX
{
	enum class Buttons : int;

	class GamePadButtons
	{
	public:
		GamePadButtons(Buttons);

		bool A();
		
		bool B();
		
		bool Back();
		
		bool BigButton();
		
		bool LeftShoulder();
		
		bool LeftStick();
		
		bool RightShoulder();
		
		bool RightStick();
		
		bool Start();
		
		bool X();
		
		bool Y();
		
		friend bool operator==(const GamePadButtons&, const GamePadButtons&);
		friend bool operator!=(const GamePadButtons&, const GamePadButtons&);
	private:
		Buttons _buttons;
	};
}


#endif