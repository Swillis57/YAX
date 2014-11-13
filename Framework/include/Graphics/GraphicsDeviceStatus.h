#ifndef _GRAPHICS_DEVICE_STATUS_H
#define _GRAPHICS_DEVICE_STATUS_H

namespace YAX
{
	enum class GraphicsDeviceStatus : int 
	{
		Lost,
		Normal,
		NotReset
	};
}


#endif