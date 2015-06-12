#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H

#include <vector>

#include "../../../external/glew/include/GL/glew.h"
#include "GraphicsResource.h"
#include "../Utils.h"

namespace YAX
{
	enum class IndexElementSize : GLsizeiptr;
	enum class BufferUsage : GLenum;

	class IndexBuffer : public GraphicsResource
	{
	public:
		IndexBuffer(YAX::IndexElementSize size, i32 count, YAX::BufferUsage usage);
		IndexBuffer(const IndexBuffer&) = delete;
		IndexBuffer& operator=(const IndexBuffer&) = delete;
		IndexBuffer(IndexBuffer&&);
		IndexBuffer& operator=(IndexBuffer&&);

		virtual ~IndexBuffer();

		YAX::BufferUsage BufferUsage();

		i32 IndexCount();

		YAX::IndexElementSize IndexElementSize();

		template<
			typename indexType,
			typename = std::enable_if<
				std::is_integral<indexType>::value 
				&& is_leq_to<sizeof(indexType), sizeof(i32)>::value
			>::type
		>
		void GetData(i32 offset, std::vector<indexType>& dest, i32 startIdx, i32 count)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufID);
			indexType* data = glMapBufferRange(
				GL_ELEMENT_ARRAY_BUFFER,
				offset,
				(GLsizeiptr)count * sizeof(indexType),
				GL_MAP_READ_BIT);

			if (data != nullptr)
			{
				if (dest.capacity() < startIdx + count)
					dest.resize(startIdx + count);

				dest.assign(data, data + count);
				glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
			}
			
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		template<
			typename indexType,
			typename = std::enable_if<
				std::is_integral<indexType>
				&& is_leq_to<sizeof(indexType), sizeof(i32)>
			>::type
		>
		void GetData(std::vector<indexType>& dest)
		{
			GetData(0, dest, 0, _indCount);
		}

		template<
			typename indexType,
			typename = std::enable_if<
				std::is_integral<indexType>
				&& is_leq_to<sizeof(indexType), sizeof(i32)>
			>::type
		>
		void GetData(std::vector<indexType>& dest, i32 startIdx, i32 count)
		{
			GetData(0, dest, startIdx, count);
		}

		template<
			typename indexType,
			typename = std::enable_if<
				std::is_integral<indexType>
				&& is_leq_to<sizeof(indexType), sizeof(i32)>
			>::type
		>
		void SetData(i32 offset, const std::vector<indexType>& src, i32 startIdx, i32 count)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufID);
			indexType* data = glMapBufferRange(
				GL_ELEMENT_ARRAY_BUFFER,
				offset,
				(GLsizeiptr)count * sizeof(indexType),
				GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT);

			if (data != nullptr)
			{
				for (int i = 0; i < count; i++)
				{
					data[i] = src[i + startIdx];
				}

				glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
			}

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		template<
			typename indexType,
			typename = std::enable_if<
				std::is_integral<indexType>
				&& is_leq_to<sizeof(indexType), sizeof(i32)>
			>::type
		>
		void SetDate(const std::vector<indexType>& src)
		{
			SetData(0, src, 0, _indCount);
		}

		template<
			typename indexType,
			typename = std::enable_if<
				std::is_integral<indexType>
				&& is_leq_to<sizeof(indexType), sizeof(i32)>
			>::type
		>
		void SetData(const std::vector<indexType>& src, i32 startIdx, i32 count)
		{
			SetData(0, src, startIdx, count);
		}

	protected:
		YAX::BufferUsage _bufUsage;
		i32 _indCount;
		YAX::IndexElementSize _elemSize;
		GLuint _bufID;
	};
}


#endif