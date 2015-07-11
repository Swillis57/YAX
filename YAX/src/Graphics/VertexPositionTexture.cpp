#include "../../include/Graphics/VertexPositionTexture.h"

#include "../../include/Graphics/VertexElementFormat.h"
#include "../../include/Graphics/VertexElementUsage.h"

namespace YAX
{
    const YAX::VertexDeclaration VertexPositionTexture::VertexDeclaration = YAX::VertexDeclaration({
        VertexElement(0, VertexElementFormat::Vector3, VertexElementUsage::Position, 0),
        VertexElement(12, VertexElementFormat::Vector2, VertexElementUsage::TextureCoordinate, 0)
    });

    VertexPositionTexture::VertexPositionTexture(const Vector3& pos, const Vector2& coord)
        : IVertexType(),
        _pos(pos),
        _texCoord(coord)
    {
        _vertDecl = &VertexDeclaration;
    }

    Vector2 VertexPositionTexture::TextureCoordinate() const
    {
        return _texCoord;
    }

    void VertexPositionTexture::TextureCoordinate(const Vector2& coord)
    {
        _texCoord = coord;
    }

    Vector3 VertexPositionTexture::Position() const
    {
        return _pos;
    }

    void VertexPositionTexture::Position(const Vector3& pos)
    {
        _pos = pos;
    }

    bool operator==(const VertexPositionTexture& lhs, const VertexPositionTexture& rhs)
    {
        return (lhs._pos == rhs._pos
            && lhs._texCoord == rhs._texCoord);
    }
}