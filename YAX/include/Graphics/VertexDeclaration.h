#ifndef _VERTEX_DECLARATION_H
#define _VERTEX_DECLARATION_H

#include <vector>
#include "VertexElement.h"


namespace YAX
{
    class VertexDeclaration
    {
    public:
        VertexDeclaration(std::vector<VertexElement>);
        VertexDeclaration(i32 stride, std::vector<VertexElement>);
        
        i32 VertexStride() const;

        std::vector<VertexElement> GetVertexElements() const;

        friend bool operator==(const VertexDeclaration&, const VertexDeclaration&);
        friend bool operator!=(const VertexDeclaration&, const VertexDeclaration&);

    private:
        std::vector<VertexElement> _elements;
        i32 _stride;
    };
}


#endif