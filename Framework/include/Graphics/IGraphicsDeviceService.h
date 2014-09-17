#ifndef I_GRAPHICS_DEVICE_SERVICE
#define I_GRAPHICS_DEVICE_SERVICE

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