#ifndef _DYNAMIC_VERTEX_BUFFER_H
#define _DYNAMIC_VERTEX_BUFFER_H

#include "VertexBuffer.h"

namespace XNA
{
    enum BufferUsage : short;
    
    class GraphicsDevice;

    class DynamicVertexBuffer : public VertexBuffer
    {
    public:
        DynamicVertexBuffer(GraphicsDevice&, VertexDeclaration, i32, BufferUsage);
    }
}


#endif

