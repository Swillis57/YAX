#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H

#include <memory>

#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	enum class IndexElementSize;
	enum class BufferUsage;

	class IndexBuffer : public GraphicsResource
	{
		IndexBuffer(XNA::GraphicsDevice&, XNA::IndexElementSize, i32, XNA::BufferUsage);
		IndexBuffer(IndexBuffer&&);

		virtual ~IndexBuffer();

		XNA::BufferUsage BufferUsage();
		i32 IndexCount();
		XNA::IndexElementSize IndexElementSize();

		template<typename vertType>
		void GetData(i32, std::vector<vertType>, i32, i32);

		template<typename vertType>
		void GetData(std::vector<vertType>);

		template<typename vertType>
		void GetData(std::vector<vertType>, i32, i32);

		template<typename vertType>
		void SetData(i32, std::vector<vertType>, i32, i32);

		template<typename vertType>
		void SetDate(std::vector<vertType>);

		template<typename vertType>
		void SetData(std::vector<vertType>, i32, i32);

	private:
		XNA::BufferUsage _bufUsage;
		i32 _indCount;
		XNA::IndexElementSize _elemSize;
		std::vector<i32> _indices;
	};
}


#endif