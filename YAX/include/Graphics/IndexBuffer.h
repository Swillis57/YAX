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

#include "../../../external/glew/include/GL/glew.h"
#include "GraphicsResource.h"
#include "../Utils.h"

namespace YAX
{
	enum class IndexElementSize : int;
	enum class BufferUsage : int;

	class IndexBuffer : public GraphicsResource
	{
		IndexBuffer(YAX::GraphicsDevice&, YAX::IndexElementSize, i32, YAX::BufferUsage);
		IndexBuffer(const IndexBuffer&) = delete;
		IndexBuffer& operator=(const IndexBuffer&) = delete;
		IndexBuffer(IndexBuffer&&);
		IndexBuffer& operator=(IndexBuffer&&);

		virtual ~IndexBuffer();

		YAX::BufferUsage BufferUsage();

		i32 IndexCount();

		YAX::IndexElementSize IndexElementSize();

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
		YAX::BufferUsage _bufUsage;
		i32 _indCount;
		YAX::IndexElementSize _elemSize;
		GLuint _bufID;
	};
}


#endif