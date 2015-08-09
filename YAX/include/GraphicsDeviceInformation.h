#ifndef	_GRAPHICS_DEVICE_INFORMATION_H
#define _GRAPHICS_DEVICE_INFORMATION_H

#include "Graphics/PresentationParameters.h"

namespace YAX
{
	enum class GraphicsProfile : ui32;
	class GraphicsAdapter;

	class GraphicsDeviceInformation
	{
	public:
		GraphicsDeviceInformation();

		GraphicsAdapter* Adapter();
		void Adapter(GraphicsAdapter*);

		YAX::GraphicsProfile GraphicsProfile();
		void GraphicsProfile(YAX::GraphicsProfile);

		YAX::PresentationParameters PresentationParameters();
		void PresentationParameters(YAX::PresentationParameters);
	
	private:
		GraphicsAdapter* _adapter;
		YAX::GraphicsProfile _profile;
		YAX::PresentationParameters _params;
	};
}

#endif