#ifndef	_GRAPHICS_DEVICE_INFORMATION_H
#define _GRAPHICS_DEVICE_INFORMATION_H

#include "Graphics/GraphicsAdapter.h"
#include "Graphics/PresentationParameters.h"

namespace YAX
{
	enum class GraphicsProfile : int;

	class GraphicsDeviceInformation
	{
	public:
		GraphicsDeviceInformation();

		GraphicsAdapter Adapter;

		YAX::GraphicsProfile GraphicsProfile;

		YAX::PresentationParameters PresentationParameters;
	};
}

#endif