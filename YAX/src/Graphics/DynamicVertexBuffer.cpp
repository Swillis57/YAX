#include "Graphics/DynamicVertexBuffer.h"

#include "Graphics/BufferUsage.h"

namespace YAX
{
    DynamicVertexBuffer::DynamicVertexBuffer(const YAX::VertexDeclaration& vertDecl, i32 vertCount, YAX::BufferUsage usage)
        : VertexBuffer(vertDecl, vertCount, usage)
    {
        glBindBuffer(GL_ARRAY_BUFFER, _id);
        glBufferData(GL_ARRAY_BUFFER, _vertDecl.VertexStride() * _vertCount, nullptr, GL_STREAM_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    DynamicVertexBuffer::DynamicVertexBuffer(DynamicVertexBuffer&& old)
        : VertexBuffer(std::move(old))
    {}

    DynamicVertexBuffer& DynamicVertexBuffer::operator=(DynamicVertexBuffer&& old)
    {
        VertexBuffer::operator=(std::move(old));

        return *this;
    }
}