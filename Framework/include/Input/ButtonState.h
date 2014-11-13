#ifndef _BUTTON_STATE_H
#define _BUTTON_STATE_H

namespace YAX
{
	enum class ButtonState : int 
	{
		Released = 0,
		Pressed = 1,
		Repeated = 2
	};
}

#endif