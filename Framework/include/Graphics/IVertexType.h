#ifndef VERTEX_TYPE
#define VERTEX_TYPE

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