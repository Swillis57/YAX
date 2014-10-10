#ifndef _VERTEX_BUFFER_BINDING_H
#define _VERTEX_BUFFER_BINDING_H

#include "VertexBuffer.h"
#include "../Utils.h"

namespace XNA
{
	struct VertexBufferBinding
	{
		VertexBufferBinding(VertexBuffer);
		VertexBufferBinding(VertexBuffer, i32);
		VertexBufferBinding(VertexBuffer, i32, i32);

		i32 InstanceFrequency();

		XNA::VertexBuffer& VertexBuffer();

		i32 VertexOffset();

	private:
		i32 _instFreq, _vertOffset;
		XNA::VertexBuffer& _vertBuf;
	};
}


#endif