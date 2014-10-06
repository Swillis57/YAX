#ifndef _I_GRAPHICS_DEVICE_SERVICE_H
#define _I_GRAPHICS_DEVICE_SERVICE_H

namespace XNA
{
	class GraphicsDevice;

	class IGraphicsDeviceService
	{
	public:
		XNA::GraphicsDevice& GraphicsDevice;
	};
}

#endif