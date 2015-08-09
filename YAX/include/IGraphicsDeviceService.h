#ifndef _GDS_INTERFACE
#define _GDS_INTERFACE

#include <memory>
#include "IGameService.h"

namespace YAX
{
	class GraphicsDevice;

	class IGraphicsDeviceService : public IGameService
	{
	public:
		YAX::GraphicsDevice* GraphicsDevice() { return _graphicsDev.get(); }
		~IGraphicsDeviceService() = default;

	protected:
		std::unique_ptr<YAX::GraphicsDevice> _graphicsDev;
	};
	
}
#endif