#ifndef _GRAPHICS_RESOURCE_H
#define _GRAPHICS_RESOURCE_H

#include <string>

namespace YAX
{
	class GraphicsDevice;

	class GraphicsResource
	{
	public:
		GraphicsResource(YAX::GraphicsDevice&, std::string);
		virtual ~GraphicsResource() = 0;

		YAX::GraphicsDevice& GraphicsDevice();
		std::string Name();
	
	protected:
		YAX::GraphicsDevice& _device;
		std::string _name;
	};
}


#endif