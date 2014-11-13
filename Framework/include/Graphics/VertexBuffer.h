#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include <vector>
#include "../GLEW/glew.h"
#include "GraphicsResource.h"
#include "VertexDeclaration.h"
#include "../Utils.h"

namespace YAX
{
	enum class BufferUsage : int;

	class GraphicsDevice;

	class VertexBuffer : public GraphicsResource
	{
	public:
		VertexBuffer(YAX::GraphicsDevice&, YAX::VertexDeclaration, i32, BufferUsage);
		VertexBuffer(const VertexBuffer&) = delete;
		VertexBuffer& operator=(const VertexBuffer&) = delete;
		VertexBuffer(VertexBuffer&&);
		VertexBuffer& operator=(VertexBuffer&&);

		YAX::BufferUsage BufferUsage() const;
		i32 VertexCount() const;
		YAX::VertexDeclaration VertexDeclaration() const;

		void GetData(i32, std::vector<YAX::VertexDeclaration>&, i32, i32, i32) const;
		void GetData(std::vector<YAX::VertexDeclaration>&) const;
		void GetData(std::vector<YAX::VertexDeclaration>&, i32, i32) const;

		void SetData(i32, const std::vector<YAX::VertexDeclaration>&, i32, i32, i32);
		void SetDate(const std::vector<YAX::VertexDeclaration>&);
		void SetData(const std::vector<YAX::VertexDeclaration>&, i32, i32);

	private:
		YAX::BufferUsage _usage;
		i32 _vertCount;
		YAX::VertexDeclaration _vertDecl;
		GLuint _id;
	};
}


#endif