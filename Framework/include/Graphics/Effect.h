#ifndef EFFECT
#define EFFECT

#include <vector>
#include "GraphicsResource.h"

namespace XNA
{
	typedef char byte;

	class GraphicsDevice;

	class Effect : GraphicsResource
	{
	public:
		Effect(const Effect&);
		Effect(const XNA::GraphicsDevice&, std::vector<byte>);
	
		
	};
}


#endif
