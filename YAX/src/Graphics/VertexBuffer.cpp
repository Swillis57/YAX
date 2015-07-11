#include "../../include/Graphics/VertexBuffer.h"

#include <exception>
#include "../../include/Graphics/BufferUsage.h"

namespace YAX
{
    VertexBuffer::VertexBuffer(YAX::VertexDeclaration decl, i32 vertCount, YAX::BufferUsage usage)
        : GraphicsResource(""),
        _vertDecl(decl),
        _vertCount(vertCount),
        _usage(usage)
    {
        if (vertCount < 0)
            throw std::invalid_argument("vertCount cannot be negative.");

        glGenBuffers(1, &_id);
        glBindBuffer(GL_ARRAY_BUFFER, _id);
        glBufferData(GL_ARRAY_BUFFER, decl.VertexStride() * vertCount, nullptr, (GLenum)usage);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    VertexBuffer::VertexBuffer(VertexBuffer&& old)
        : GraphicsResource(std::move(old)),
        _vertDecl(old._vertDecl),
        _vertCount(old._vertCount),
        _usage(old._usage)
    {
        old._vertCount = 0;
    }

    VertexBuffer& VertexBuffer::operator=(VertexBuffer&& old)
    {
        GraphicsResource::operator=(std::move(old));
        this->_vertCount = old._vertCount;
        this->_vertDecl = old._vertDecl;
        this->_usage = old._usage;
        old._vertCount = 0;
        
        return *this;
    }

    YAX::BufferUsage VertexBuffer::BufferUsage() const
    {
        return _usage;
    }

    i32 VertexBuffer::VertexCount() const
    {
        return _vertCount;
    }

    YAX::VertexDeclaration VertexBuffer::VertexDeclaration() const
    {
        return _vertDecl;
    }
}