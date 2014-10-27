#ifndef _BUTTONS_H
#define _BUTTONS_H

namespace XNA
{
	enum Buttons : short
	{
		A,
		B, 
		Back,
		BigButton,
		DPadDown,
		DPadLeft,
		DPadRight,
		DPadUp,
		LeftShoulder,
		LeftStick,
		LeftThumbstickDown,
		LeftThumbstickLeft,
		LeftThumbstickRight,
		LeftThumbstickUp,
		LeftTrigger,
		RightShoulder,
		RightStick,
		RightThumbstickDown,
		RightThumbstickLeft,
		RightThumbstickRight,
		RightThumbstickUp,
		RightTrigger,
		Start,
		X,
		Y
	};

	inline Buttons operator|(Buttons lhs, Buttons rhs)
	{
		return (Buttons)(static_cast<short>(lhs) | static_cast<short>(rhs));
	}

	inline Buttons& operator|=(Buttons& lhs, Buttons rhs)
	{
		lhs = lhs | rhs;
	}
}

#endif