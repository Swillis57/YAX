#ifndef _SPRITE_BATCH_H
#define _SPRITE_BATCH_H

#include <vector>
#include "DynamicIndexBuffer.h"
#include "DynamicVertexBuffer.h"
#include "GraphicsResource.h"
#include "../Geometry/Rectangle.h"
#include "SpriteEffects.h"
#include "Texture2D.h"

namespace XNA
{
	enum class SpriteSortMode : int;
	enum class SpriteEffects : int;

	class BlendState;
	class SamplerState;
	class DepthStencilState;
	class RasterizerState;
	class Effect;
	class Matrix;
	class Rectangle;
	class SpriteFont;
	class Texture2D;
	struct Color;
	struct Vector2;

	class SpriteBatch : public GraphicsResource
	{
		struct SpriteInfo
		{
			Rectangle src;
			Rectangle dest;
			Texture2D tex;
			SpriteEffects fx;
		};

	public:
		SpriteBatch(XNA::GraphicsDevice&);
		SpriteBatch(const SpriteBatch&) = delete;
		SpriteBatch& operator=(const SpriteBatch&) = delete;
		SpriteBatch(SpriteBatch&&);
		SpriteBatch& operator=(SpriteBatch&&);

		void Begin();
		void Begin(SpriteSortMode, const BlendState&);
		void Begin(SpriteSortMode, const BlendState&, const SamplerState&, const DepthStencilState&, const RasterizerState&);
		void Begin(SpriteSortMode, const BlendState&, const SamplerState&, const DepthStencilState&, const RasterizerState&, const Effect&);
		void Begin(SpriteSortMode, const BlendState&, const SamplerState&, const DepthStencilState&, const RasterizerState&, const Effect&, const Matrix&);

		void Draw(const Texture2D&, const Rectangle&, const Color&);
		void Draw(const Texture2D&, const Rectangle&, const Rectangle&, const Color&);
		void Draw(const Texture2D&, const Rectangle&, const Rectangle&, const Color&, float, const Vector2&, SpriteEffects, float);
		void Draw(const Texture2D&, const Vector2&, const Color&);
		void Draw(const Texture2D&, const Vector2&, const Rectangle&);
		void Draw(const Texture2D&, const Vector2&, const Rectangle&, const Color&, float, const Vector2&, float, SpriteEffects, float);
		void Draw(const Texture2D&, const Vector2&, const Rectangle&, const Color&, float, const Vector2&, const Vector2&, SpriteEffects, float);

		void DrawString(const SpriteFont&, std::string, const Vector2&, const Color&);
		void DrawString(const SpriteFont&, std::string, const Vector2&, const Color&, float, const Vector2&, float, SpriteEffects, float);
		void DrawString(const SpriteFont&, std::string, const Vector2&, const Color&, float, const Vector2&, const Vector2&, SpriteEffects, float);
		
		void End();

	private:
		DynamicIndexBuffer _idxBuf;
		DynamicVertexBuffer _vertBuf;
		std::vector<SpriteInfo> _spriteQueue;
	};
}


#endif