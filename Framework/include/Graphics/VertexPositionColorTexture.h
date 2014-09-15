#ifndef VERTEX_POSITION_COLOR_TEXTURE
#define VERTEX_POSITION_COLOR_TEXTURE


#include "../Color.h"
#include "IVertexType.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"

namespace XNA
{
	struct VertexPositionColorTexture : public IVertexType
	{
		VertexPositionColorTexture(Vector3, Color, Vector2);

		XNA::Color Color();
		void Color(XNA::Color);

		Vector3 Position();
		void Position(Vector3);

		Vector2 TextureCoordinate();
		void TextureCoordinate(Vector2);

		static const XNA::VertexDeclaration VertexDeclaration();
		static const void VertexDeclaration(XNA::VertexDeclaration);

		friend bool operator==(const VertexPositionColorTexture&, const VertexPositionColorTexture&);
		friend bool operator!=(const VertexPositionColorTexture&, const VertexPositionColorTexture&);

	private:
		XNA::Color _color;
		Vector3 _pos;
		Vector2 _texCoord;
		static const XNA::VertexDeclaration _vertDecl;
	};
}


#endif