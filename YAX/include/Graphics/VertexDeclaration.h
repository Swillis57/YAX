#ifndef _VERTEX_DECLARATION_H
#define _VERTEX_DECLARATION_H

#include <vector>
#include "GraphicsResource.h"
#include "VertexElement.h"


namespace YAX
{
    class VertexDeclaration : public GraphicsResource
    {
    public:
        VertexDeclaration(std::vector<VertexElement>);
        VertexDeclaration(i32 stride, std::vector<VertexElement>);
        
        i32 VertexStride() const;

        std::vector<VertexElement> GetVertexElements() const;

    private:
        std::vector<VertexElement> _elements;
        i32 _stride;
    };
}


#endif