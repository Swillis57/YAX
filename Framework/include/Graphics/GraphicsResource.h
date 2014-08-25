#ifndef GRAPHICS_RESOURCE
#define GRAPHICS_RESOURCE

#include <memory>
#include <string>

namespace XNA
{
	class GraphicsDevice;

	class GraphicsResource
	{
	public:
		virtual ~GraphicsResource(); 

		std::shared_ptr<XNA::GraphicsDevice> GraphicsDevice();
		std::string Name();
		std::shared_ptr<void> Tag();
	
	private:
		std::shared_ptr<XNA::GraphicsDevice> _device;
		std::string _name;
		std::shared_ptr<void> _tag;
	};
}


#endif