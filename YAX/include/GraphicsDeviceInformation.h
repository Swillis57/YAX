#ifndef	_GRAPHICS_DEVICE_INFORMATION_H
#define _GRAPHICS_DEVICE_INFORMATION_H

#include "../../YAX.Graphics/include/GraphicsAdapter.h"
#include "../../YAX.Graphics/include/PresentationParameters.h"

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