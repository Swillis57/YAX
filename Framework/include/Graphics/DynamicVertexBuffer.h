#ifndef _DYNAMIC_VERTEX_BUFFER_H
#define _DYNAMIC_VERTEX_BUFFER_H

#include "VertexBuffer.h"

namespace XNA
{
	enum class SetDataOptions : int;
	enum class BufferUsage : int;
	
	class GraphicsDevice;
	class VertexDeclaration;
	
	template<typename vertType>
	class DynamicVertexBuffer : public VertexBuffer
	{
	public:
		DynamicVertexBuffer(GraphicsDevice&, const VertexDeclaration&, i32, BufferUsage);
		//DynamicVertexBuffer(GraphicsDevice&, Type, i32, BufferUsage);

		//Only here for completeness, OpenGL handles lost contexts in the driver
		bool IsContentLost() const;

		void SetData(i32, i32, std::vector<vertType>, i32, i32, i32, SetDataOptions);
		void SetData(std::vector<vertType>, i32, i32, SetDataOptions);
	};
}


#endif

