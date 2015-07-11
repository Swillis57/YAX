#include "../../include/Graphics/DynamicIndexBuffer.h"

#include "../../include/Graphics/IndexElementSize.h"

namespace YAX
{
    DynamicIndexBuffer::DynamicIndexBuffer(YAX::IndexElementSize elemSize, i32 count, YAX::BufferUsage usage)
        : IndexBuffer(elemSize, count, usage)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)_elemSize, nullptr, GL_STREAM_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    DynamicIndexBuffer::DynamicIndexBuffer(DynamicIndexBuffer&& old)
        : IndexBuffer(std::move(old))
    {}

    DynamicIndexBuffer& DynamicIndexBuffer::operator=(DynamicIndexBuffer&& old)
    {
        IndexBuffer::operator=(std::move(old));

        return *this;
    }
}