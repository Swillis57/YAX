#ifndef _VERTEX_TYPE_H
#define _VERTEX_TYPE_H

#include "VertexDeclaration.h"

namespace XNA
{
	struct IVertexType
	{
	    XNA::VertexDeclaration VertexDeclaration();
		virtual ~IVertexType() = 0;
	protected:
		XNA::VertexDeclaration _vertDecl;
	};
}


#endif