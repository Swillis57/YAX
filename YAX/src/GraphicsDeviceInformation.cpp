#include "../include/GraphicsDeviceInformation.h"
#include "../include/Graphics/GraphicsProfile.h"

namespace YAX
{
	GraphicsDeviceInformation::GraphicsDeviceInformation()
		: _adapter(GraphicsAdapter::DefaultAdapter()),
		  _profile(YAX::GraphicsProfile::HiDef),
	  	  _params(YAX::PresentationParameters())
	{}

	GraphicsAdapter* GraphicsDeviceInformation::Adapter()
	{
		return _adapter;
	}

	void GraphicsDeviceInformation::Adapter(GraphicsAdapter* ga)
	{
		_adapter = ga;
	}

	YAX::GraphicsProfile GraphicsDeviceInformation::GraphicsProfile()
	{
		return _profile;
	}

	void GraphicsDeviceInformation::GraphicsProfile(YAX::GraphicsProfile gp)
	{
		_profile = gp;
	}

	YAX::PresentationParameters GraphicsDeviceInformation::PresentationParameters()
	{
		return _params;
	}

	void GraphicsDeviceInformation::PresentationParameters(YAX::PresentationParameters pp)
	{
		_params = pp;
	}
}