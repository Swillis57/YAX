#ifndef VERTEX_ELEMENT
#define VERTEX_ELEMENT

#include "../Utils.h"
#include "VertexElementFormat.h"

namespace XNA
{
	enum VertexElementUsage : short;

	class VertexElement
	{
	public:
		VertexElement(i32, XNA::VertexElementFormat, XNA::VertexElementUsage, i32);

		i32 Offset();
		void Offset(i32);

		i32 UsageIndex();
		void UsageIndex(i32);
		
		XNA::VertexElementFormat VertexElementFormat();
		void VertexElementFormat(XNA::VertexElementFormat);

		XNA::VertexElementUsage VertexElementUsage();
		void VertexElementUsage(XNA::VertexElementUsage);
	
		friend bool operator==(const VertexElement&, const VertexElement&);
		friend bool operator!=(const VertexElement&, const VertexElement&);

	private:
		i32 _offset, _usageIdx;
		XNA::VertexElementFormat _fmt;
		XNA::VertexElementUsage _usg;
	};
}


#endif