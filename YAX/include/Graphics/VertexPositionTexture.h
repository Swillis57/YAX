#ifndef _VERTEX_POSITION_TEXTURE_H
#define _VERTEX_POSITION_TEXTURE_H


#include "IVertexType.h"
#include "../Vector2.h"
#include "../Vector3.h"
#include "VertexDeclaration.h "

namespace YAX
{
    struct VertexPositionTexture : public IVertexType<VertexPositionTexture>
    {
    public:
        VertexPositionTexture(const Vector3& pos, const Vector2& coord);
        ~VertexPositionTexture() = default;

        Vector2 TextureCoordinate() const;
        void TextureCoordinate(const Vector2&);

        Vector3 Position() const;
        void Position(const Vector3&);

        friend bool operator==(const VertexPositionTexture&, const VertexPositionTexture&);
        friend bool operator!=(const VertexPositionTexture&, const VertexPositionTexture&);

    private:
        Vector3 _pos;
        Vector2 _texCoord;
    };
}


#endif