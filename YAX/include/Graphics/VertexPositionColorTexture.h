#ifndef _VERTEX_POSITION_COLOR_TEXTURE_H
#define _VERTEX_POSITION_COLOR_TEXTURE_H


#include "../Color.h"
#include "IVertexType.h"
#include "../Vector2.h"
#include "../Vector3.h"

namespace YAX
{
	struct VertexPositionColorTexture : public IVertexType
	{
		VertexPositionColorTexture(Vector3, Color, Vector2);

		YAX::Color Color();
		void Color(YAX::Color);

		Vector3 Position();
		void Position(Vector3);

		Vector2 TextureCoordinate();
		void TextureCoordinate(Vector2);

		static const YAX::VertexDeclaration VertexDeclaration();
		static const void VertexDeclaration(YAX::VertexDeclaration);

		friend bool operator==(const VertexPositionColorTexture&, const VertexPositionColorTexture&);
		friend bool operator!=(const VertexPositionColorTexture&, const VertexPositionColorTexture&);

	private:
		YAX::Color _color;
		Vector3 _pos;
		Vector2 _texCoord;
		static const YAX::VertexDeclaration _vertDecl;
	};
}


#endif