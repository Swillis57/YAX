#ifndef	_GRAPHICS_DEVICE_INFORMATION_H
#define _GRAPHICS_DEVICE_INFORMATION_H

#include "../../YAX.Graphics/include/GraphicsAdapter.h"
#include "../../YAX.Graphics/include/PresentationParameters.h"
#include "Utils.h"

namespace YAX
{
	enum class GraphicsProfile : int;

	class GraphicsDeviceInformation
	{
	public:
		GraphicsDeviceInformation();

		GraphicsAdapter Adapter();
		void Adapter(const GraphicsAdapter&);

		YAX::GraphicsProfile GraphicsProfile();
		void GraphicsProfile(YAX::GraphicsProfile);

		YAX::PresentationParameters PresentationParameters();
		void PresentationParameters(YAX::PresentationParameters);

	private:
		YAX::GraphicsAdapter _adapter;
		YAX::GraphicsProfile _profile;
		YAX::PresentationParameters _params;
	};
}

#endif