#ifndef _DYNAMIC_VERTEX_BUFFER_H
#define _DYNAMIC_VERTEX_BUFFER_H

#include "VertexBuffer.h"

namespace YAX
{
    enum class SetDataOptions : ui32;
    enum class BufferUsage : ui32;
    
    class GraphicsDevice;
    class VertexDeclaration;
    
    class DynamicVertexBuffer : public VertexBuffer
    {
    public:
        DynamicVertexBuffer(const YAX::VertexDeclaration& vertDecl, i32 vertCount, YAX::BufferUsage usage);
        DynamicVertexBuffer(const DynamicVertexBuffer&) = delete;
        DynamicVertexBuffer& operator=(const DynamicVertexBuffer&) = delete;
        DynamicVertexBuffer(DynamicVertexBuffer&&);
        DynamicVertexBuffer& operator=(DynamicVertexBuffer&&);
        ~DynamicVertexBuffer() = default;

        template<typename vertType>
        void SetData(i32 offsetInBytes, const std::vector<vertType>& src, i32 startIdx, i32 count, i32 stride, SetDataOptions option)
        {
            if (startIdx + count > src.size())
                throw std::invalid_argument("The vector is not the correct size for the amount of data requested.");

            if (offsetInBytes + count * sizeof(vertType) > _vertCount * _vertDecl.VertexStride())
                throw std::runtime_error("The buffer is not the correct size for the amount fo data requested.");

            if (stride < sizeof(vertType))
                throw std::invalid_argument("The stride is too small for the given vertex type.");

            if (count > 1 && count*stride > _vertCount*_vertDecl.VertexStride())
                throw std::invalid_argument("The vertex stride is larger than the vertex buffer.");

            i32 isBound = 0;
            glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &isBound);
            if (isBound == _id)
                throw std::runtime_error("Cannot modify a buffer while it is in use.");

            glBindBuffer(GL_ARRAY_BUFFER, _id);
            if (option == SetDataOptions::Discard)
                glBufferData(GL_ARRAY_BUFFER, _vertDecl.VertexStride() * _vertCount, nullptr, GL_STREAM_DRAW);

            glBufferSubData(GL_ARRAY_BUFFER, offsetInBytes, count*stride, &src[startIdx]);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        template<typename vertType>
        void SetData(const std::vector<vertType>& src, i32 startIdx, i32 count, SetDataOptions option)
        {
            SetData(0, src, startIdx, count, sizeof(vertType), option);
        }
    };
}


#endif

