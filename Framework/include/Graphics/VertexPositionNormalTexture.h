#ifndef _VERTEX_POSITION_NORMAL_TEXTURE_H
#define _VERTEX_POSITION_NORMAL_TEXTURE_H


#include "IVertexType.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"

namespace YAX
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

		static const YAX::VertexDeclaration VertexDeclaration();
		static const void VertexDeclaration(YAX::VertexDeclaration);

		friend bool operator==(const VertexPositionNormalTexture&, const VertexPositionNormalTexture&);
		friend bool operator!=(const VertexPositionNormalTexture&, const VertexPositionNormalTexture&);

	private:
		Vector3 _pos, _norm;
		Vector2 _texCoord;
		static const YAX::VertexDeclaration _vertDecl;
	};
}


#endif