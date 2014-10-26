#ifndef _BUTTON_STATE_H
#define _BUTTON_STATE_H

namespace XNA
{
	enum ButtonState : short
	{
		Released = 0,
		Pressed = 1,
		Repeated = 2
	};
}

#endif