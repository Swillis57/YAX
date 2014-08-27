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
		IndexBuffer(IndexBuffer&&);

		XNA::BufferUsage BufferUsage();
		i32 IndexCount();
		XNA::IndexElementSize IndexElementSize();

	private:
		XNA::BufferUsage _bufUsage;
		i32 _indCount;
		XNA::IndexElementSize _elemSize;
		
	};
}


#endif