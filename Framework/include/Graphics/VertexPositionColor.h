#ifndef _VERTEX_POSITION_COLOR_H
#define _VERTEX_POSITION_COLOR_H


#include "../Color.h"
#include "IVertexType.h"
#include "../Math/Vector3.h"
#include "VertexDeclaration.h "

namespace XNA
{
	struct VertexPositionColor : public IVertexType
	{
		VertexPositionColor(Vector3, XNA::Color);
		
		XNA::Color Color();
		void Color(XNA::Color);

		Vector3 Position();
		void Position(Vector3);

		static const XNA::VertexDeclaration VertexDeclaration();
		static const void VertexDeclaration(XNA::VertexDeclaration);
	
		friend bool operator==(const VertexPositionColor&, const VertexPositionColor&);
		friend bool operator!=(const VertexPositionColor&, const VertexPositionColor&);

	private:
		XNA::Color _color;
		Vector3 _pos;
		static const XNA::VertexDeclaration _vertDecl;

	};
}


#endif