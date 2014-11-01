#ifndef _DYNAMIC_INDEX_BUFFER_H
#define _DYNAMIC_INDEX_BUFFER_H

#include <vector>
#include "IndexBuffer.h"
#include "../Utils.h"

namespace XNA
{
	enum class BufferUsage;
	enum class IndexElementSize;
	enum class SetDataOptions;

	class GraphicsDevice;

	template<typename indexType>
	class DynamicIndexBuffer : public IndexBuffer<indexType>
	{
	public:
		DynamicIndexBuffer(GraphicsDevice&, IndexElementSize, i32, BufferUsage);
		//DynamicIndexBuffer(GraphicsDevice&, Type, i32, BufferUsage);

		//Only here for completeness' sake, OpenGL handles context resets in the driver
		bool IsContentLost(); 
	
		void SetData<indexType>(i32, std::vector<indexType>, i32, i32, SetDataOptions) override;
		void SetData<indexType>(std::vector<indexType>, i32, i32, SetDataOptions) override;
		
	};
}


#endif
