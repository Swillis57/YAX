#ifndef _MODEL_MESH_PART_H
#define _MODEL_MESH_PART_H

#include "Effect.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "../Utils.h"

namespace XNA
{
	class ModelMeshPart
	{
	public:
		XNA::Effect Effect();
		void Effect(XNA::Effect);

		XNA::IndexBuffer IndexBuffer();

		i32 NumVertices();

		i32 PrimitiveCount();

		i32 StartIndex();

		void* Tag(); //TODO: Use something better than a void*
		void Tag(void*);

		XNA::VertexBuffer VertexBuffer();

		i32 VertexOffset();

	private:
		XNA::Effect _effect;
		XNA::IndexBuffer _idxBuf;
		XNA::VertexBuffer _vertBuf;
		i32 _numVerts, _primCount, _startIdx, _vertOffset;
		void* _tag;
	};
}


#endif