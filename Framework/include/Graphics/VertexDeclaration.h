#ifndef VERTEX_DECLARATION
#define VERTEX_DECLARATION

#include <vector>
#include "GraphicsResource.h"
#include "VertexElement.h"


namespace XNA
{
	class VertexDeclaration : public GraphicsResource
	{
	public:
		VertexDeclaration(i32, std::vector<VertexElement>);
		VertexDeclaration(std::vector<VertexElement>);

		i32 VertexStride();

		std::vector<VertexElement> GetVertexElements();

	private:
		std::vector<VertexElement> _elements;
	};
}


#endif