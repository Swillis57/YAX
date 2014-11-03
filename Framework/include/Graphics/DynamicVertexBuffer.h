#ifndef _DYNAMIC_VERTEX_BUFFER_H
#define _DYNAMIC_VERTEX_BUFFER_H

#include "VertexBuffer.h"
#include "VertexDeclaration.h"

namespace XNA
{
	enum class SetDataOptions : int;
	enum class BufferUsage : int;
	
	class GraphicsDevice;
	
	template<typename vertType>
	class DynamicVertexBuffer : public VertexBuffer
	{
	public:
		DynamicVertexBuffer(GraphicsDevice&, VertexDeclaration, i32, BufferUsage);
		//DynamicVertexBuffer(GraphicsDevice&, Type, i32, BufferUsage);

		bool IsContentLost();

		void SetData(i32, i32, std::vector<vertType>, i32, i32, i32, SetDataOptions);
		void SetData(std::vector<vertType>, i32, i32, SetDataOptions);
	};
}


#endif

