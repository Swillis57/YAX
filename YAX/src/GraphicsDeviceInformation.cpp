#include "../include/GraphicsDeviceInformation.h"
#include "../../YAX.Graphics/include/GraphicsProfile.h"

namespace YAX
{
	GraphicsDeviceInformation::GraphicsDeviceInformation()
		: Adapter(GraphicsAdapter::DefaultAdapter()),
		  GraphicsProfile(YAX::GraphicsProfile::HiDef),
	  	  PresentationParameters(YAX::PresentationParameters())
	{}

}