#ifndef _VERTEX_POSITION_COLOR_H
#define _VERTEX_POSITION_COLOR_H


#include "../Color.h"
#include "IVertexType.h"
#include "../Vector3.h"
#include "VertexDeclaration.h "

namespace YAX
{
    struct VertexPositionColor : public IVertexType<VertexPositionColor>
    {
    public:
        VertexPositionColor(const Vector3& pos, const YAX::Color& color);
        ~VertexPositionColor() = default;

        YAX::Color Color() const;
        void Color(const YAX::Color&);

        Vector3 Position() const;
        void Position(const Vector3&);
    
        friend bool operator==(const VertexPositionColor&, const VertexPositionColor&);
        friend bool operator!=(const VertexPositionColor&, const VertexPositionColor&);

    private:
        Vector3 _pos;
        YAX::Color _color;

    };
}


#endif