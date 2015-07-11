#include "../../include/Graphics/VertexPositionColorTexture.h"

#include "../../include/Graphics/VertexElementFormat.h"
#include "../../include/Graphics/VertexElementUsage.h"

namespace YAX
{
    const YAX::VertexDeclaration VertexPositionColorTexture::VertexDeclaration = YAX::VertexDeclaration({
        VertexElement(0, VertexElementFormat::Vector3, YAX::VertexElementUsage::Position, 0),
        VertexElement(12, VertexElementFormat::Color, VertexElementUsage::Color, 0),
        VertexElement(16, VertexElementFormat::Vector2, VertexElementUsage::TextureCoordinate, 0)
    });

    VertexPositionColorTexture::VertexPositionColorTexture(const Vector3& pos, const YAX::Color& color, const Vector2& texCoord)
        : IVertexType(),
        _pos(pos),
        _color(color),
        _texCoord(texCoord)
    {
        _vertDecl = &VertexDeclaration;
    }

    YAX::Color VertexPositionColorTexture::Color() const
    {
        return _color;
    }

    void VertexPositionColorTexture::Color(const YAX::Color& color)
    {
        _color = color;
    }

    Vector3 VertexPositionColorTexture::Position() const
    {
        return _pos;
    }

    void VertexPositionColorTexture::Position(const Vector3& pos)
    {
        _pos = pos;
    }

    Vector2 VertexPositionColorTexture::TextureCoordinate() const
    {
        return _texCoord;
    }

    void VertexPositionColorTexture::TextureCoordinate(const Vector2& coord)
    {
        _texCoord = coord;
    }

    bool operator==(const VertexPositionColorTexture& lhs, const VertexPositionColorTexture& rhs)
    {
        return lhs._color == rhs._color
            && lhs._pos == rhs._pos
            && lhs._texCoord == rhs._texCoord;
    }

    bool operator!=(const VertexPositionColorTexture& lhs, const VertexPositionColorTexture& rhs)
    {
        return !(lhs == rhs);
    }
}