#ifndef _GAME_PAD_H
#define _GAME_PAD_H

namespace YAX
{
	enum class PlayerIndex : int;

	class GamePadCapabilities;
	class GamePadDeadZone;
	class GamePadState;

	class GamePad
	{
	public:
		static GamePadCapabilities GetCapabilities(PlayerIndex);
		static GamePadState GetState(PlayerIndex);
		static GamePadState GetState(PlayerIndex, GamePadDeadZone);
	};
}


#endif