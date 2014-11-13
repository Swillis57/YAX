#ifndef _GAME_PAD_TRIGGERS_H
#define _GAME_PAD_TRIGGERS_H

namespace YAX
{
	struct GamePadTriggers
	{
		GamePadTriggers(float, float);
		
		float Left();
		float Right();

		friend bool operator==(const GamePadTriggers&, const GamePadTriggers&);
		friend bool operator!=(const GamePadTriggers&, const GamePadTriggers&);

	private:
		float _left, _right;
	};

	
}


#endif