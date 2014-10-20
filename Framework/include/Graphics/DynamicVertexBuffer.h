#ifndef _DYNAMIC_VERTEX_BUFFER_H
#define _DYNAMIC_VERTEX_BUFFER_H

#include "VertexBuffer.h"

namespace XNA
{
    enum SetDataOptions : short;
    enum BufferUsage : short;
    
    class GraphicsDevice;
    
    template<typename vertType>
    class DynamicVertexBuffer : public VertexBuffer
    {
    public:
        DynamicVertexBuffer(GraphicsDevice&, VertexDeclaration, i32, BufferUsage);
        DynamicVertexBuffer(GraphicsDevice&, VertexDeclaration, i32, BufferUsage);

        void SetData(i32, i32, std::vector<vertType>, i32, i32, i32, SetDataOptions);
        void SetData(std::vector<vertType>, i32, i32, SetDataOptions);
    }
}


#endif

