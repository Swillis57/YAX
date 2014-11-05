#ifndef _DYNAMIC_INDEX_BUFFER_H
#define _DYNAMIC_INDEX_BUFFER_H

#include <vector>
#include "IndexBuffer.h"
#include "../Utils.h"

namespace XNA
{
	enum class BufferUsage : int;
	enum class IndexElementSize : int;
	enum class SetDataOptions : int;

	class GraphicsDevice;

	class DynamicIndexBuffer : public IndexBuffer
	{
	public:
		DynamicIndexBuffer(XNA::GraphicsDevice&, XNA::IndexElementSize, i32, XNA::BufferUsage);
		//DynamicIndexBuffer(GraphicsDevice&, Type, i32, BufferUsage);

		//Only here for completeness, OpenGL handles lost contexts in the driver
		bool IsContentLost() const;
	
		template<typename indexType>
		void SetData<indexType>(i32, std::vector<indexType>, i32, i32, SetDataOptions);
		
		template<typename indexType>
		void SetData<indexType>(std::vector<indexType>, i32, i32, SetDataOptions);
		
	};
	
	
}


#endif
