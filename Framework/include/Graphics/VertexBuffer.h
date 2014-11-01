#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include <vector>
#include "GraphicsResource.h"
#include "VertexDeclaration.h"
#include "../Utils.h"

namespace XNA
{
	enum class BufferUsage;

	class GraphicsDevice;

	class VertexBuffer : public GraphicsResource
	{
	public:
		//VertexBuffer(GraphicsDevice&, Type, i32, BufferUsage);	 //Tricky to implement without using a template
		VertexBuffer(XNA::GraphicsDevice&, XNA::VertexDeclaration, i32, BufferUsage);

		XNA::BufferUsage BufferUsage();
		i32 VertexCount();
		XNA::VertexDeclaration VertexDeclaration();

		void GetData(i32, std::vector<XNA::VertexDeclaration>, i32, i32, i32);
		void GetData(std::vector<XNA::VertexDeclaration>);
		void GetData(std::vector<XNA::VertexDeclaration>, i32, i32);

		void SetData(i32, std::vector<XNA::VertexDeclaration>, i32, i32, i32);
		void SetDate(std::vector<XNA::VertexDeclaration>);
		void SetData(std::vector<XNA::VertexDeclaration>, i32, i32);

	private:
		XNA::BufferUsage _usage;
		i32 _vertCount;
		XNA::VertexDeclaration _vertDecl;
		std::vector<XNA::VertexDeclaration> _data;
	};
}


#endif