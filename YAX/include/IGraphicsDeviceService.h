#ifndef _GDS_INTERFACE
#define _GDS_INTERFACE

#include "../../YAX.Graphics/include/GraphicsDevice.h"

namespace YAX
{
	class IGraphicsDeviceService
	{
	public:
		YAX::GraphicsDevice& GraphicsDevice();
	
	protected:
		YAX::GraphicsDevice _graphicsDevice;
	};
	
}
#endif