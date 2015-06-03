#include "../include/GraphicsDeviceInformation.h"
#include "../include/Graphics/GraphicsProfile.h"

namespace YAX
{
	GraphicsDeviceInformation::GraphicsDeviceInformation()
		: Adapter(GraphicsAdapter::DefaultAdapter()),
		  GraphicsProfile(YAX::GraphicsProfile::HiDef),
	  	  PresentationParameters(YAX::PresentationParameters())
	{}

}