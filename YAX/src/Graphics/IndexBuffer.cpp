#include "../../include/Graphics/IndexBuffer.h"

#include "../../include/Graphics/IndexElementSize.h"
#include "../../include/Graphics/BufferUsage.h"

namespace YAX
{
	IndexBuffer::IndexBuffer(YAX::IndexElementSize size, i32 count, YAX::BufferUsage usage)
		: _elemSize(size), 
		_indCount(count), 
		_bufUsage(usage), 
		GraphicsResource("")
	{
		glGenBuffers(1, &_bufID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)_elemSize * _indCount, nullptr, (GLenum)_bufUsage);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &_bufID);
		_bufID = 0;
	}

	IndexBuffer::IndexBuffer(IndexBuffer&& old)
		: _elemSize(old._elemSize),
		_indCount(old._indCount),
		_bufUsage(old._bufUsage),
		_bufID(old._bufID),
		GraphicsResource("")
	{
		old._bufID = 0;
	}

	IndexBuffer& IndexBuffer::operator=(IndexBuffer&& old)
	{
		this->_elemSize = old._elemSize;
		this->_indCount = old._indCount;
		this->_bufUsage = old._bufUsage;
		this->_bufID = old._bufID;

		old._bufID = 0;

		return *this;
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