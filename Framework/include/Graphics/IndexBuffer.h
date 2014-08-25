#ifndef INDEX_BUFFER
#define INDEX_BUFFER

#include <memory>

#include "GraphicsResource.h"
#include "IndexElementSize.h"
#include "BufferUsage.h"
#include "../Utils.h"

namespace XNA
{
	class IndexBuffer : GraphicsResource
	{
		IndexBuffer(XNA::GraphicsDevice&, XNA::IndexElementSize, i32, XNA::BufferUsage);

		XNA::BufferUsage BufferUsage();
		i32 IndexCount();
		i32 IndexElementSize();
		
	};
}


#endif