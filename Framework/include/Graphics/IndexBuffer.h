#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H

#include <memory>

#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	enum IndexElementSize : int;
	enum BufferUsage : short;

	template<typename indexType>
	class IndexBuffer : public GraphicsResource
	{
		IndexBuffer(XNA::GraphicsDevice&, XNA::IndexElementSize, i32, XNA::BufferUsage);
		IndexBuffer(IndexBuffer&&);

		virtual ~IndexBuffer();

		XNA::BufferUsage BufferUsage();
		i32 IndexCount();
		XNA::IndexElementSize IndexElementSize();

		void GetData(i32, std::vector<indexType>, i32, i32);
		void GetData(std::vector<indexType>);
		void GetData(std::vector<indexType>, i32, i32);

		void SetData(i32, std::vector<indexType>, i32, i32);
		void SetDate(std::vector<indexType>);
		void SetData(std::vector<indexType>, i32, i32);

	private:
		XNA::BufferUsage _bufUsage;
		i32 _indCount;
		XNA::IndexElementSize _elemSize;
		std::vector<indexType> _indices;
	};
}


#endif