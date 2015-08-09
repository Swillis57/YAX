#include "Graphics/VertexPositionNormalTexture.h"

#include "Graphics/VertexElementFormat.h"
#include "Graphics/VertexElementUsage.h"

namespace YAX
{
    const YAX::VertexDeclaration VertexPositionNormalTexture::VertexDeclaration = YAX::VertexDeclaration({
        VertexElement(0, VertexElementFormat::Vector3, VertexElementUsage::Position, 0),
        VertexElement(12, VertexElementFormat::Vector3, VertexElementUsage::Normal, 0),
        VertexElement(24, VertexElementFormat::Vector2, VertexElementUsage::TextureCoordinate, 0)
    });

    VertexPositionNormalTexture::VertexPositionNormalTexture(const Vector3& pos, const Vector3& norm, const Vector2& texCoord)
        : IVertexType(),
        _pos(pos),
        _norm(norm),
        _texCoord(texCoord)
    {}

    Vector3 VertexPositionNormalTexture::Normal() const
    {
        return _norm;
    }

    void VertexPositionNormalTexture::Normal(const Vector3& norm)
    {
        _norm = norm;
    }

    Vector3 VertexPositionNormalTexture::Position() const
    {
        return _pos;
    }

    void VertexPositionNormalTexture::Position(const Vector3& pos)
    {
        _pos = pos;
    }

    Vector2 VertexPositionNormalTexture::TextureCoordinate() const
    {
        return _texCoord;
    }

    void VertexPositionNormalTexture::TextureCoordinate(const Vector2& coord)
    {
        _texCoord = coord;
    }

    bool operator==(const VertexPositionNormalTexture& lhs, const VertexPositionNormalTexture& rhs)
    {
        return (lhs._norm == rhs._norm
            && lhs._pos == rhs._pos
            && lhs._texCoord == rhs._texCoord);
    }

    bool operator!=(const VertexPositionNormalTexture& lhs, const VertexPositionNormalTexture& rhs)
    {
        return !(lhs == rhs);
    }
}