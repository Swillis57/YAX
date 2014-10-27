#ifndef _GAME_PAD_STATE_H
#define _GAME_PAD_STATE_H

#include <vector>
#include "GamePadThumbSticks.h"
#include "GamePadTriggers.h"
#include "GamePadButtons.h"
#include "GamePadDPad.h"
#include "../Utils.h"

namespace XNA
{
	enum Buttons : short;

	class Vector2;

	struct GamePadState
	{
		GamePadState(const GamePadThumbSticks&, const GamePadTriggers&, const GamePadButtons&, const GamePadDPad&);
		GamePadState(const Vector2&, const Vector2&, float, float, std::vector<XNA::Buttons>);

		GamePadButtons Buttons();
		
		GamePadDPad DPad();
			
		bool IsConnected();

		i32 PacketNumber();

		GamePadThumbSticks ThumbSticks();

		GamePadTriggers Triggers();

		bool IsButtonDown();

		bool IsButtonUp();

		friend bool operator==(const GamePadState&, const GamePadState&);
		friend bool operator!=(const GamePadState&, const GamePadState&);

	private:
		GamePadButtons _buttons;
		GamePadDPad _dpad;
		GamePadThumbSticks _sticks;
		GamePadTriggers _triggers;
		i32 _packetNum;

	};
}

#endif