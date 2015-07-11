#include "../../include/Graphics/VertexDeclaration.h"

#include <exception>

namespace YAX
{
    VertexDeclaration::VertexDeclaration(std::vector<VertexElement> elements)
        : VertexDeclaration(0, elements)
    {}

    VertexDeclaration::VertexDeclaration(i32 stride, std::vector<VertexElement> elements)
        : GraphicsResource(""),
        _stride(stride)
    {
        if (elements.size() == 0)
            throw std::invalid_argument("elements cannot be empty.");

        _elements = elements;
    }

    i32 VertexDeclaration::VertexStride() const
    {
        return _stride;
    }

    std::vector<VertexElement> VertexDeclaration::GetVertexElements() const
    {
        return _elements;
    }
}