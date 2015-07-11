#include "../../include/Graphics/VertexPositionColor.h"

#include "../../include/Graphics/VertexElement.h"
#include "../../include/Graphics/VertexElementFormat.h"
#include "../../include/Graphics/VertexElementUsage.h"

namespace YAX
{
    const YAX::VertexDeclaration VertexPositionColor::VertexDeclaration = YAX::VertexDeclaration({
        VertexElement(0, VertexElementFormat::Vector3, VertexElementUsage::Position, 0),
        VertexElement(12, VertexElementFormat::Color, VertexElementUsage::Color, 0)
    });

    VertexPositionColor::VertexPositionColor(const Vector3& pos, const YAX::Color& color)
        : IVertexType(),
        _pos(pos),
        _color(color)
    {
        _vertDecl = &VertexDeclaration;
    }

    YAX::Color VertexPositionColor::Color() const
    {
        return _color;
    }

    void VertexPositionColor::Color(const YAX::Color& color)
    {
        _color = color;
    }

    Vector3 VertexPositionColor::Position() const
    {
        return _pos;
    }

    void VertexPositionColor::Position(const Vector3& pos)
    {
        _pos = pos;
    }

    bool operator==(const VertexPositionColor& lhs, const VertexPositionColor& rhs)
    {
        return lhs._pos == rhs._pos
            && lhs._color == rhs._color;
    }

    bool operator!=(const VertexPositionColor& lhs, const VertexPositionColor& rhs)
    {
        return !(lhs == rhs);
    }
}