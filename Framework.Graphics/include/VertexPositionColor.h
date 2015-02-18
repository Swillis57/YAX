#ifndef _VERTEX_POSITION_COLOR_H
#define _VERTEX_POSITION_COLOR_H


#include "../../Framework/include/Color.h"
#include "IVertexType.h"
#include "../../Framework.Math/include/Vector3.h"
#include "VertexDeclaration.h "

namespace YAX
{
	struct VertexPositionColor : public IVertexType
	{
		VertexPositionColor(Vector3, YAX::Color);
		
		YAX::Color Color();
		void Color(YAX::Color);

		Vector3 Position();
		void Position(Vector3);

		static const YAX::VertexDeclaration VertexDeclaration();
		static const void VertexDeclaration(YAX::VertexDeclaration);
	
		friend bool operator==(const VertexPositionColor&, const VertexPositionColor&);
		friend bool operator!=(const VertexPositionColor&, const VertexPositionColor&);

	private:
		YAX::Color _color;
		Vector3 _pos;
		static const YAX::VertexDeclaration _vertDecl;

	};
}


#endif