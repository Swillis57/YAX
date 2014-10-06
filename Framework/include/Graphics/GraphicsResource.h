#ifndef _GRAPHICS_RESOURCE_H
#define _GRAPHICS_RESOURCE_H

#include <memory>
#include <string>

namespace XNA
{
	class GraphicsDevice;

	class GraphicsResource
	{
	public:
		GraphicsResource(XNA::GraphicsDevice&, std::string);
		GraphicsResource(XNA::GraphicsDevice&, std::string, void*);
		virtual ~GraphicsResource(); 

		XNA::GraphicsDevice& GraphicsDevice();
		std::string Name();
		//void* Tag();
	
	private:
		XNA::GraphicsDevice& _device;
		std::string _name;
		//std::unique_ptr<void> _tag;
	};
}


#endif