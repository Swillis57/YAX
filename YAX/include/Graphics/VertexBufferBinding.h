#ifndef _VERTEX_BUFFER_BINDING_H
#define _VERTEX_BUFFER_BINDING_H

#include "VertexBuffer.h"
#include "../Utils.h"

namespace YAX
{
    struct VertexBufferBinding
    {
    public:
        VertexBufferBinding(YAX::VertexBuffer* buf, i32 offset = 0, i32 instanceFrequency = 0);

        i32 InstanceFrequency() const;		 

        YAX::VertexBuffer* VertexBuffer() const;

        i32 VertexOffset() const;

    private:
        i32 _instFreq, _vertOffset;
        YAX::VertexBuffer* _vertBuf;
    };
}


#endif