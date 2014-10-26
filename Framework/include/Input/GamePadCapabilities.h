#ifndef _GAME_PAD_CAPABILITIES_H
#define _GAME_PAD_CAPABILITIES_H

namespace XNA
{
	enum GamePadType : short;

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
		bool _hasAButton;
		bool _hasBackButton;
		bool _hasBButton;
		bool _hasBigButton;
		bool _hasDPadDownButton;
		bool _hasDPadLeftButton;
		bool _hasDPadRightButton;
		bool _hasDPadUpButton;
		bool _hasLeftShoulderButton;
		bool _hasLeftStickButton;
		bool _hasLeftTrigger;
		bool _hasLeftVibrationMotor;
		bool _hasLeftXThumbStick;
		bool _hasLeftYThumbStick;
		bool _hasRightShoulderButton;
		bool _hasRightStickButton;
		bool _hasRightTrigger;
		bool _hasRightVibrationMotor;
		bool _hasRightXThumbStick;
		bool _hasRightYThumbStick;
		bool _hasStartButton;
		bool _hasVoiceSupport;
		bool _hasXButton;
		bool _hasYButton;
		bool _isConnected;
	};
}

#endif