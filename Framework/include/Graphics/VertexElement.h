#ifndef _VERTEX_ELEMENT_H
#define _VERTEX_ELEMENT_H

#include "../Utils.h"
#include "VertexElementFormat.h"

namespace YAX
{
	enum class VertexElementUsage : int;

	class VertexElement
	{
	public:
		VertexElement(i32, YAX::VertexElementFormat, YAX::VertexElementUsage, i32);

		i32 Offset();
		void Offset(i32);

		i32 UsageIndex();
		void UsageIndex(i32);
		
		YAX::VertexElementFormat VertexElementFormat();
		void VertexElementFormat(YAX::VertexElementFormat);

		YAX::VertexElementUsage VertexElementUsage();
		void VertexElementUsage(YAX::VertexElementUsage);
	
		friend bool operator==(const VertexElement&, const VertexElement&);
		friend bool operator!=(const VertexElement&, const VertexElement&);

	private:
		i32 _offset, _usageIdx;
		YAX::VertexElementFormat _fmt;
		YAX::VertexElementUsage _usg;
	};
}


#endif