#ifndef _DYNAMIC_INDEX_BUFFER_H
#define _DYNAMIC_INDEX_BUFFER_H

#include "IndexBuffer.h"
#include "../Utils.h"

namespace XNA
{
	enum BufferUsage : short;
	enum IndexElementSize : int;

	class GraphicsDevice;

	template<typename indexType>
	class DynamicIndexBuffer : public IndexBuffer<indexType>
	{
	public:
		DynamicIndexBuffer(GraphicsDevice&, IndexElementSize, i32, BufferUsage);
		//DynamicIndexBuffer(GraphicsDevice&, Type, i32, BufferUsage);

		//Only here for completeness' sake, OpenGL handles context resets in the driver
		bool IsContentLost(); 


	};
}


#endif