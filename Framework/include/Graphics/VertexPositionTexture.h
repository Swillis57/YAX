#ifndef VERTEX_POSITION_TEXTURE
#define VERTEX_POSITION_TEXTURE


#include "IVertexType.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "VertexDeclaration.h "

namespace XNA
{
	struct VertexPositionTexture : public IVertexType
	{
		VertexPositionTexture(Vector3, Vector2);

		Vector2 TextureCoordinate();
		void TextureCoordinate(Vector2);

		Vector3 Position();
		void Position(Vector3);

		static const XNA::VertexDeclaration VertexDeclaration();
		static const void VertexDeclaration(XNA::VertexDeclaration);

		friend bool operator==(const VertexPositionTexture&, const VertexPositionTexture&);
		friend bool operator!=(const VertexPositionTexture&, const VertexPositionTexture&);

	private:
		Vector2 _texCoord;
		Vector3 _pos;
		static const XNA::VertexDeclaration _vertDecl;

	};
}


#endif