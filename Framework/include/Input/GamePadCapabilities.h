#ifndef _GAME_PAD_CAPABILITIES_H
#define _GAME_PAD_CAPABILITIES_H

#include "../Utils.h"

namespace XNA
{
	enum class GamePadType : int;

	struct GamePadCapabilities
	{
		XNA::GamePadType GamePadType();

		bool HasAButton();

		bool HasBackButton();

		bool HasBButton();

		bool HasBigButton();

		bool HasDPadDownButton();

		bool HasDPadLeftButton();

		bool HasDPadRightButton();

		bool HasDPadUpButton();

		bool HasLeftShoulderButton();

		bool HasLeftStickButton();

		bool HasLeftTrigger();

		bool HasLeftVibrationMotor();

		bool HasLeftXThumbStick();

		bool HasLeftYThumbStick();

		bool HasRightShoulderButton();

		bool HasRightStickButton();

		bool HasRightTrigger();

		bool HasRightVibrationMotor();

		bool HasRightXThumbStick();

		bool HasRightYThumbStick();

		bool HasStartButton();

		bool HasVoiceSupport();

		bool HasXButton();

		bool HasYButton();

		bool IsConnected();

	private:
		ui32 _buttons;
	};
}

#endif