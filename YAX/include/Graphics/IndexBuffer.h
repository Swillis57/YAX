#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H

#include <exception>
#include <vector>
#include "BufferUsage.h"
#include "../../../external/glew/include/GL/glew.h"
#include "GraphicsResource.h"
#include "../Utils.h"

namespace YAX
{
    enum class IndexElementSize : ui32;

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

        template<typename indexType>
        void GetData(i32 offset, std::vector<indexType>& dest, i32 startIdx, i32 count)
        {
            if (_bufUsage == BufferUsage::WriteOnly)
                throw std::runtime_error("Cannot read from a WriteOnly buffer.");

            if (dest.capacity() < startIdx + count) dest.resize(startIdx + count);
                
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
            glGetBufferSubData(
                GL_ELEMENT_ARRAY_BUFFER,
                offset,
                count*sizeof(indexType),
                &dest[startIdx]
            );

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        template<typename indexType>
        void GetData(std::vector<indexType>& dest)
        {
            GetData(0, dest, 0, _indCount);
        }

        template<typename indexType>
        void GetData(std::vector<indexType>& dest, i32 startIdx, i32 count)
        {
            GetData(0, dest, startIdx, count);
        }

        template<typename indexType>
        void SetData(i32 offset, const std::vector<indexType>& src, i32 startIdx, i32 count)
        {
            if (startIdx + count > src.size())
                throw std::invalid_argument("The vector is not the correct size for the amount of data requested.");

            if (offset + count * sizeof(indexType) > (GLsizeiptr)_elemSize * _indCount)
                throw std::runtime_error("The buffer is not the correct size for the amount of data requested.");

            i32 isBound = 0;
            glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &isBound);
            if (isBound == _id)
                throw std::runtime_error("Cannot modify a buffer while it is in use.");

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
            glBufferSubData(
                GL_ELEMENT_ARRAY_BUFFER,
                offset,
                count*sizeof(indexType),
                &src[startIdx]
            );
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        template<typename indexType>
        void SetDate(const std::vector<indexType>& src)
        {
            SetData(0, src, 0, _indCount);
        }

        template<typename indexType>
        void SetData(const std::vector<indexType>& src, i32 startIdx, i32 count)
        {
            SetData(0, src, startIdx, count);
        }

    protected:
        YAX::BufferUsage _bufUsage;
        i32 _indCount;
        YAX::IndexElementSize _elemSize;
        GLuint _id;
    };
}


#endif