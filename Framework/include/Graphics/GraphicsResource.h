#ifndef _GRAPHICS_RESOURCE_H
#define _GRAPHICS_RESOURCE_H

#include <string>

namespace XNA
{
	class GraphicsDevice;

	class GraphicsResource
	{
	public:
		GraphicsResource(XNA::GraphicsDevice&, std::string);
		virtual ~GraphicsResource() = 0;

		XNA::GraphicsDevice& GraphicsDevice();
		std::string Name();
	
	protected:
		XNA::GraphicsDevice& _device;
		std::string _name;
	};
}


#endif