#ifndef _DYNAMIC_INDEX_BUFFER_H
#define _DYNAMIC_INDEX_BUFFER_H


#define SETDATA_SPECIALIZE(idxType) \
	template void SetData<idxType>(i32, std::vector<idxType>, i32, i32, SetDataOptions); \
	template void SetData<idxType>(std::vector<idxType>, i32, i32, SetDataOptions);

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
	
		template<typename indexType>
		void SetData(i32, std::vector<indexType>, i32, i32, SetDataOptions);
		
		template<typename indexType>
		void SetData(std::vector<indexType>, i32, i32, SetDataOptions);
		
	};
	
	
}


#endif
