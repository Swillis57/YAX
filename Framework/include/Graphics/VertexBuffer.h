#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include <vector>
#include "GraphicsResource.h"
#include "VertexDeclaration.h"
#include "../Utils.h"

namespace XNA
{
	enum BufferUsage : short;

	class GraphicsDevice;

	template<typename VertType>
	class VertexBuffer : public GraphicsResource
	{
	public:
		VertexBuffer(GraphicsDevice&, i32, BufferUsage);
		VertexBuffer(GraphicsDevice&, VertexDeclaration, i32, BufferUsage);

		XNA::BufferUsage BufferUsage();
		i32 VertexCount();
		XNA::VertexDeclaration VertexDeclaration();

		void GetData(i32, std::vector<VertType>, i32, i32, i32);
		void GetData(std::vector<VertType>);
		void GetData(std::vector<VertType>, i32, i32);

		void SetData(i32, std::vector<VertType>, i32, i32, i32);
		void SetDate(std::vector<VertType>);
		void SetData(std::vector<VertType>, i32, i32);

	private:
		XNA::BufferUsage _usage;
		i32 _vertCount;
		XNA::VertexDeclaration _vertDecl;
	};
}


#endif