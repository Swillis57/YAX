#ifndef _VERTEX_TYPE_H
#define _VERTEX_TYPE_H

#include "VertexDeclaration.h"

namespace YAX
{
	struct IVertexType
	{
		virtual ~IVertexType() = 0;

	    YAX::VertexDeclaration VertexDeclaration();

	protected:
		YAX::VertexDeclaration _vertDecl;
	};
}


#endif