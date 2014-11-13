#ifndef _VERTEX_POSITION_TEXTURE_H
#define _VERTEX_POSITION_TEXTURE_H


#include "IVertexType.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "VertexDeclaration.h "

namespace YAX
{
	struct VertexPositionTexture : public IVertexType
	{
		VertexPositionTexture(Vector3, Vector2);

		Vector2 TextureCoordinate();
		void TextureCoordinate(Vector2);

		Vector3 Position();
		void Position(Vector3);

		static const YAX::VertexDeclaration VertexDeclaration();
		static const void VertexDeclaration(YAX::VertexDeclaration);

		friend bool operator==(const VertexPositionTexture&, const VertexPositionTexture&);
		friend bool operator!=(const VertexPositionTexture&, const VertexPositionTexture&);

	private:
		Vector2 _texCoord;
		Vector3 _pos;
		static const YAX::VertexDeclaration _vertDecl;

	};
}


#endif