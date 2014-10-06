#ifndef _GAME_COMPONENT_H
#define _GAME_COMPONENT_H

#include <memory>
#include "Game.h"
#include "GameTime.h"

namespace XNA
{
	#pragma deprecated(GameComponent)
	class GameComponent
	{
	public:
		bool Enabled;
		int UpdateOrder;

		GameComponent(const Game&);
		virtual ~GameComponent();

		virtual void Initialize();
		virtual void Update(GameTime);
		const Game& GetGame();

	private:
		const Game& game;
	};

	GameComponent::GameComponent(const Game& g)
		: game(g)
	{}

	const Game& GameComponent::GetGame()
	{
		return game;
	}
}



#endif