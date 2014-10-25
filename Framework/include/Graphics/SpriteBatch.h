#ifndef _SPRITE_BATCH_H
#define _SPRITE_BATCH_H

#include "GraphicsResource.h"

namespace XNA
{
	enum SpriteSortMode : short;
	enum SpriteEffects : short;

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
	public:
		SpriteBatch(XNA::GraphicsDevice&);

		void Begin();
		void Begin(SpriteSortMode, const BlendState&);
		void Begin(SpriteSortMode, const BlendState&, const SamplerState&, const DepthStencilState&, const RasterizerState&);
		void Begin(SpriteSortMode, const BlendState&, const SamplerState&, const DepthStencilState&, const RasterizerState&, const Effect&);
		void Begin(SpriteSortMode, const BlendState&, const SamplerState&, const DepthStencilState&, const RasterizerState&, const Effect&, const Matrix&);

		void Draw(const Texture2D&, const Rectangle&, const Color&);
		void Draw(const Texture2D&, const Rectangle&, const Rectangle* const, const Color&);
		void Draw(const Texture2D&, const Rectangle&, const Rectangle* const, const Color&, float, const Vector2&, SpriteEffects, float);
		void Draw(const Texture2D&, const Vector2&, const Color&);
		void Draw(const Texture2D&, const Vector2&, const Rectangle* const);
		void Draw(const Texture2D&, const Vector2&, const Rectangle* const, const Color&, float, const Vector2&, float, SpriteEffects, float);
		void Draw(const Texture2D&, const Vector2&, const Rectangle* const, const Color&, float, const Vector2&, const Vector2&, SpriteEffects, float);

		void DrawString(const SpriteFont&, std::string, const Vector2&, const Color&);
		void DrawString(const SpriteFont&, std::string, const Vector2&, const Color&, float, const Vector2&, float, SpriteEffects, float);
		void DrawString(const SpriteFont&, std::string, const Vector2&, const Color&, float, const Vector2&, const Vector2&, SpriteEffects, float);
		
		void End();
	};
}


#endif