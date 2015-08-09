#ifndef _VERTEX_TYPE_H
#define _VERTEX_TYPE_H

#include "VertexDeclaration.h"

namespace YAX
{
    template<typename D>
    struct IVertexType
    {
        static const YAX::VertexDeclaration VertexDeclaration;
    };
}


#endif