#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H

#include <memory>

#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	enum IndexElementSize : int;
	enum BufferUsage : short;

	class IndexBuffer : public GraphicsResource
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