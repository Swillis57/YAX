#ifndef _VERTEX_TYPE_H
#define _VERTEX_TYPE_H

#include "VertexDeclaration.h"

namespace YAX
{
    struct IVertexType
    {
        virtual ~IVertexType() {};

        YAX::VertexDeclaration VertexDeclaration()
        {
            return *_vertDecl;
        }

    protected:
        const YAX::VertexDeclaration* _vertDecl;
    };
}


#endif