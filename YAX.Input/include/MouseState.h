#ifndef _MOUSE_STATE_H
#define _MOUSE_STATE_H

#include "../../Framework/include/Utils.h"

namespace YAX
{
	enum class ButtonState : int;

	struct MouseState
	{
		MouseState(i32, i32, i32, ButtonState, ButtonState, ButtonState, ButtonState, ButtonState);

		ButtonState LeftButton();

		ButtonState RightButton();

		ButtonState MiddleButton();

		i32 ScrollWheelValue();

		ButtonState XButton1();

		ButtonState XButton2();

		i32 X();

		i32 Y();

		friend bool operator==(const MouseState&, const MouseState&);
		friend bool operator!=(const MouseState&, const MouseState&);

	private:
		ButtonState _left, _right, _middle, _x1, _x2;
		i32 _x, _y, _scroll;
	};
}


#endif