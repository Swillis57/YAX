#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include <vector>
#include "../GLEW/glew.h"
#include "GraphicsResource.h"
#include "VertexDeclaration.h"
#include "../Utils.h"

namespace XNA
{
	enum class BufferUsage : int;

	class GraphicsDevice;

	class VertexBuffer : public GraphicsResource
	{
	public:
		VertexBuffer(XNA::GraphicsDevice&, XNA::VertexDeclaration, i32, BufferUsage);
		VertexBuffer(const VertexBuffer&) = delete;
		VertexBuffer& operator=(const VertexBuffer&) = delete;
		VertexBuffer(VertexBuffer&&);
		VertexBuffer& operator=(VertexBuffer&&);

		XNA::BufferUsage BufferUsage() const;
		i32 VertexCount() const;
		XNA::VertexDeclaration VertexDeclaration() const;

		void GetData(i32, std::vector<XNA::VertexDeclaration>, i32, i32, i32) const;
		void GetData(std::vector<XNA::VertexDeclaration>) const;
		void GetData(std::vector<XNA::VertexDeclaration>, i32, i32) const;

		void SetData(i32, std::vector<XNA::VertexDeclaration>, i32, i32, i32);
		void SetDate(std::vector<XNA::VertexDeclaration>);
		void SetData(std::vector<XNA::VertexDeclaration>, i32, i32);

	private:
		XNA::BufferUsage _usage;
		i32 _vertCount;
		XNA::VertexDeclaration _vertDecl;
		GLuint _id;
	};
}


#endif