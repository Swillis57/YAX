#ifndef _GAME_PAD_H
#define _GAME_PAD_H

namespace XNA
{
	enum PlayerIndex : short;

	class GamePadCapabilities;

	class GamePad
	{
	public:
		static GamePadCapabilities GetCapabilities(PlayerIndex);
	};
}


#endif