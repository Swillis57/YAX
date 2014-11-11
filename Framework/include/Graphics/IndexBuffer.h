#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H


#define GETDATA_SPECIALIZE(idxType) \
	template void GetData<idxType>(i32, std::vector<idxType>, i32, i32); \
	template void GetData<idxType>(std::vector<idxType>); \
	template void GetData<idxType>(std::vector<idxType>, i32, i32);

#define SETDATA_SPECIALIZE(idxType) \
	template void SetData<idxType>(i32, std::vector<idxType>, i32, i32); \
	template void SetData<idxType>(std::vector<idxType>); \
	template void SetData<idxType>(std::vector<idxType>, i32, i32);


#include <memory>

#include "../GLEW/glew.h"
#include "GraphicsResource.h"
#include "../Utils.h"

namespace XNA
{
	enum class IndexElementSize : int;
	enum class BufferUsage : int;

	class IndexBuffer : public GraphicsResource
	{
		IndexBuffer(XNA::GraphicsDevice&, XNA::IndexElementSize, i32, XNA::BufferUsage);
		IndexBuffer(const IndexBuffer&) = delete;
		IndexBuffer& operator=(const IndexBuffer&) = delete;
		IndexBuffer(IndexBuffer&&);
		IndexBuffer& operator=(IndexBuffer&&);

		virtual ~IndexBuffer();

		XNA::BufferUsage BufferUsage();

		i32 IndexCount();

		XNA::IndexElementSize IndexElementSize();

		template<typename indexType>
		void GetData(i32, std::vector<indexType>&, i32, i32);

		template<typename indexType>
		void GetData(std::vector<indexType>&);

		template<typename indexType>
		void GetData(std::vector<indexType>&, i32, i32);

		template<typename indexType>
		void SetData(i32, const std::vector<indexType>&, i32, i32);

		template<typename indexType>
		void SetDate(const std::vector<indexType>&);

		template<typename indexType>
		void SetData(const std::vector<indexType>&, i32, i32);

	protected:
		XNA::BufferUsage _bufUsage;
		i32 _indCount;
		XNA::IndexElementSize _elemSize;
		GLuint _bufID;
	};
}


#endif