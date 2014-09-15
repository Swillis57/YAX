#ifndef VERTEX_POSITION_NORMAL_TEXTURE
#define VERTEX_POSITION_NORMAL_TEXTURE


#include "IVertexType.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"

namespace XNA
{
	struct VertexPositionNormalTexture : public IVertexType
	{
		VertexPositionNormalTexture(Vector3, Vector3, Vector2);

		Vector3 Normal();
		void Normal(Vector3);

		Vector3 Position();
		void Position(Vector3);

		Vector2 TextureCoordinate();
		void TextureCoordinate(Vector2);

		static const XNA::VertexDeclaration VertexDeclaration();
		static const void VertexDeclaration(XNA::VertexDeclaration);

		friend bool operator==(const VertexPositionNormalTexture&, const VertexPositionNormalTexture&);
		friend bool operator!=(const VertexPositionNormalTexture&, const VertexPositionNormalTexture&);

	private:
		Vector3 _pos, _norm;
		Vector2 _texCoord;
		static const XNA::VertexDeclaration _vertDecl;
	};
}


#endif