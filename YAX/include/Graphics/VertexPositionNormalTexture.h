#ifndef _VERTEX_POSITION_NORMAL_TEXTURE_H
#define _VERTEX_POSITION_NORMAL_TEXTURE_H

#include "IVertexType.h"
#include "../Vector2.h"
#include "../Vector3.h"

namespace YAX
{
    struct VertexPositionNormalTexture : public IVertexType
    {
    public:
        static const YAX::VertexDeclaration VertexDeclaration;
        
        VertexPositionNormalTexture(const Vector3& pos, const Vector3& norm, const Vector2& texCoord);
        ~VertexPositionNormalTexture() = default;

        Vector3 Normal() const;
        void Normal(const Vector3&);

        Vector3 Position() const;
        void Position(const Vector3&);

        Vector2 TextureCoordinate() const;
        void TextureCoordinate(const Vector2&);

        friend bool operator==(const VertexPositionNormalTexture&, const VertexPositionNormalTexture&);
        friend bool operator!=(const VertexPositionNormalTexture&, const VertexPositionNormalTexture&);

    private:
        Vector3 _pos, _norm;
        Vector2 _texCoord;
    };
}


#endif