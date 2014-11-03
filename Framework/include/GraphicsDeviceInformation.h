#ifndef	_GRAPHICS_DEVICE_INFORMATION_H
#define _GRAPHICS_DEVICE_INFORMATION_H

#include "Graphics/GraphicsAdapter.h"
#include "Graphics/PresentationParameters.h"
#include "Utils.h"

namespace XNA
{
	enum class GraphicsProfile : int;

	class GraphicsDeviceInformation
	{
	public:
		GraphicsDeviceInformation();

		GraphicsAdapter Adapter();
		void Adapter(const GraphicsAdapter&);

		XNA::GraphicsProfile GraphicsProfile();
		void GraphicsProfile(XNA::GraphicsProfile);

		XNA::PresentationParameters PresentationParameters();
		void PresentationParameters(XNA::PresentationParameters);

	private:
		XNA::GraphicsAdapter _adapter;
		XNA::GraphicsProfile _profile;
		XNA::PresentationParameters _params;
	};
}

#endif