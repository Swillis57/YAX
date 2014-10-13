#ifndef _DRAWABLE_GAME_COMP_H
#define _DRAWABLE_GAME_COMP_H

#include "GameComponent.h"
#include "Game.h"

namespace XNA
{	
	class DrawableGameComponent : public GameComponent
	{
	public:
		int DrawOrder;
		bool Visible;

		DrawableGameComponent(Game&);
		~DrawableGameComponent();

		virtual void Draw();
		void Initialize() override;

	protected:
		virtual void LoadContent();
		virtual void UnloadContent();
	};
}






#endif