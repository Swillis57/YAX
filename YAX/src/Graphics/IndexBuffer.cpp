#include "Graphics/IndexBuffer.h"

#include "Graphics/IndexElementSize.h"
#include "Graphics/BufferUsage.h"

namespace YAX
{
    IndexBuffer::IndexBuffer(YAX::IndexElementSize size, i32 count, YAX::BufferUsage usage)
        : _elemSize(size), 
        _indCount(count), 
        _bufUsage(usage)
    {
        glGenBuffers(1, &_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)_elemSize * _indCount, nullptr, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    IndexBuffer::~IndexBuffer()
    {
        if (_id != 0)
        {
            glDeleteBuffers(1, &_id);
            _id = 0;
        }
    }

    IndexBuffer::IndexBuffer(IndexBuffer&& old)
        : _elemSize(old._elemSize),
        _indCount(old._indCount),
        _bufUsage(old._bufUsage),
        _id(old._id)
    {
        old._id = 0;
        old._indCount = 0;
    }

    IndexBuffer& IndexBuffer::operator=(IndexBuffer&& old)
    {
        this->_elemSize = old._elemSize;
        this->_indCount = old._indCount;
        this->_bufUsage = old._bufUsage;
        this->_id = old._id;

        old._id = 0;

        return *this;
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
    }

    YAX::BufferUsage IndexBuffer::BufferUsage()
    {
        return _bufUsage;
    }

    i32 IndexBuffer::IndexCount()
    {
        return _indCount;
    }

    YAX::IndexElementSize IndexBuffer::IndexElementSize()
    {
        return _elemSize;
    }
}