#ifndef _GDS_INTERFACE
#define _GDS_INTERFACE

#include <memory>
#include "../../YAX.Graphics/include/GraphicsDevice.h"

namespace YAX
{
	class IGraphicsDeviceService
	{
	public:
		YAX::GraphicsDevice* GraphicsDevice() { return _graphicsDev.get(); }
	
	protected:
		std::unique_ptr<YAX::GraphicsDevice> _graphicsDev;
	};
	
}
#endif