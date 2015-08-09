#include "Graphics/VertexBufferBinding.h"

namespace YAX
{
    VertexBufferBinding::VertexBufferBinding()
        : VertexBufferBinding(nullptr, 0, 0)
    {}

    VertexBufferBinding::VertexBufferBinding(YAX::VertexBuffer* buf, i32 offset, i32 instanceFrequency)
        : _instFreq(instanceFrequency),
        _vertOffset(offset),
        _vertBuf(buf)
    {}

    void VertexBufferBinding::Bind() const
    {   
        glBindBuffer(GL_ARRAY_BUFFER, _vertBuf->_id);
    }

    i32 VertexBufferBinding::InstanceFrequency() const
    {
        return _instFreq;
    }

    YAX::VertexBuffer* VertexBufferBinding::VertexBuffer() const
    {
        return _vertBuf;
    }

    i32 VertexBufferBinding::VertexOffset() const
    {
        return _vertOffset;
    }
}