#ifndef _DYNAMIC_INDEX_BUFFER_H
#define _DYNAMIC_INDEX_BUFFER_H


#define DIB_SPECIALIZE(idxType) \
	template void SetData<idxType>(i32, std::vector<idxType>, i32, i32, SetDataOptions); \
	template void SetData<idxType>(std::vector<idxType>, i32, i32, SetDataOptions);

#include <vector>
#include "IndexBuffer.h"
#include "../Utils.h"

namespace YAX
{
	enum class BufferUsage : int;
	enum class IndexElementSize : int;
	enum class SetDataOptions : int;

	class GraphicsDevice;

	class DynamicIndexBuffer : public IndexBuffer
	{
	public:
		DynamicIndexBuffer(YAX::GraphicsDevice&, YAX::IndexElementSize, i32, YAX::BufferUsage);
		DynamicIndexBuffer(const DynamicIndexBuffer&) = delete;
		DynamicIndexBuffer& operator=(const DynamicIndexBuffer&) = delete;
		DynamicIndexBuffer(DynamicIndexBuffer&&);
		DynamicIndexBuffer& operator=(DynamicIndexBuffer&&);
		~DynamicIndexBuffer();
	
		template<typename indexType>
		void SetData(i32, std::vector<indexType>, i32, i32, SetDataOptions);
		
		template<typename indexType>
		void SetData(std::vector<indexType>, i32, i32, SetDataOptions);
		
	};
	
	
}


#endif