#ifndef _GRAPHICS_RESOURCE_H
#define _GRAPHICS_RESOURCE_H

#include <string>

namespace YAX
{
	class GraphicsDevice;

	class GraphicsResource
	{
		friend class YAX::GraphicsDevice;

	public:
		GraphicsResource(std::string);
		virtual ~GraphicsResource();

		YAX::GraphicsDevice* GraphicsDevice();
		std::string Name();
	
	protected:
		YAX::GraphicsDevice* _device;
		std::string _name;
	};
}


#endif