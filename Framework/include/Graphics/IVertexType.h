#ifndef _VERTEX_TYPE_H
#define _VERTEX_TYPE_H

#include "VertexDeclaration.h"

namespace XNA
{
	struct IVertexType
	{
		virtual ~IVertexType() = 0;

	    XNA::VertexDeclaration VertexDeclaration();

	protected:
		XNA::VertexDeclaration _vertDecl;
	};
}


#endif