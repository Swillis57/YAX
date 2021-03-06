#ifndef _GAME_PAD_THUMB_STICKS_H
#define _GAME_PAD_THUMB_STICKS_H

#include "../../Framework.Math/include/Vector2.h"

namespace YAX
{
	struct GamePadThumbSticks
	{
		GamePadThumbSticks(const Vector2&, const Vector2&);

		Vector2 Left();
		Vector2 Right();

		friend bool operator==(const GamePadThumbSticks&, const GamePadThumbSticks&);
		friend bool operator!=(const GamePadThumbSticks&, const GamePadThumbSticks&);

	private:
		Vector2 _left, _right;
	};

	
	
}

#endif