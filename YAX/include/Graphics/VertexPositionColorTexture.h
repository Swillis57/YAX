#ifndef _VERTEX_POSITION_COLOR_TEXTURE_H
#define _VERTEX_POSITION_COLOR_TEXTURE_H


#include "../Color.h"
#include "IVertexType.h"
#include "../Vector2.h"
#include "../Vector3.h"

namespace YAX
{
    struct VertexPositionColorTexture : public IVertexType<VertexPositionColorTexture>
    {
    public:
        VertexPositionColorTexture(const Vector3& pos, const YAX::Color& color, const Vector2& texCoord);
        ~VertexPositionColorTexture() = default;

        YAX::Color Color() const;
        void Color(const YAX::Color&);

        Vector3 Position() const;
        void Position(const Vector3&);

        Vector2 TextureCoordinate() const;
        void TextureCoordinate(const Vector2&);

        friend bool operator==(const VertexPositionColorTexture&, const VertexPositionColorTexture&);
        friend bool operator!=(const VertexPositionColorTexture&, const VertexPositionColorTexture&);

    private:
        Vector3 _pos;
        YAX::Color _color;
        Vector2 _texCoord;
    };
}


#endif