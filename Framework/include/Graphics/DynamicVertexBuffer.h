#ifndef _DYNAMIC_VERTEX_BUFFER_H
#define _DYNAMIC_VERTEX_BUFFER_H


#define DVB_SPECIALIZE(vertType) \
	template void SetData<vertType>(i32, i32, std::vector<vertType>, i32, i32, i32, SetDataOptions); \
	template void SetData<vertType>(std::vector<vertType>, i32, i32, SetDataOptions);

#include "VertexBuffer.h"

namespace XNA
{
	enum class SetDataOptions : int;
	enum class BufferUsage : int;
	
	class GraphicsDevice;
	class VertexDeclaration;
	
	class DynamicVertexBuffer : public VertexBuffer
	{
	public:
		DynamicVertexBuffer(XNA::GraphicsDevice&, const XNA::VertexDeclaration&, i32, XNA::BufferUsage);
		DynamicVertexBuffer(const DynamicVertexBuffer&) = delete;
		DynamicVertexBuffer& operator=(const DynamicVertexBuffer&) = delete;
		DynamicVertexBuffer(DynamicVertexBuffer&&);
		DynamicVertexBuffer& operator=(DynamicVertexBuffer&&);
		~DynamicVertexBuffer();


		template<typename vertType>
		void SetData(i32, i32, std::vector<vertType>, i32, i32, i32, SetDataOptions);
		template<typename vertType>
		void SetData(std::vector<vertType>, i32, i32, SetDataOptions);
	};
}


#endif

