#ifndef _GAME_PAD_H
#define _GAME_PAD_H

namespace YAX
{
	enum class PlayerIndex : int;

	class GamePadCapabilities;

	class GamePad
	{
	public:
		static GamePadCapabilities GetCapabilities(PlayerIndex);
	};
}


#endif