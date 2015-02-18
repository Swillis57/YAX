#ifndef _VERTEX_BUFFER_BINDING_H
#define _VERTEX_BUFFER_BINDING_H

#include "VertexBuffer.h"
#include "../../Framework/include/Utils.h"

namespace YAX
{
	struct VertexBufferBinding
	{
		VertexBufferBinding(VertexBuffer&);
		VertexBufferBinding(VertexBuffer&, i32);
		VertexBufferBinding(VertexBuffer&, i32, i32);

		i32 InstanceFrequency() const;		 

		YAX::VertexBuffer& VertexBuffer() const;

		i32 VertexOffset() const;

	private:
		i32 _instFreq, _vertOffset;
		YAX::VertexBuffer& _vertBuf;
	};
}


#endif