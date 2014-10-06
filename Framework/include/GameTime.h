#ifndef _GAME_TIME_H
#define _GAME_TIME_H

#include "Game.h"
#include "TimeSpan.h"

namespace XNA
{
	

	class GameTime
	{
	public:
		GameTime();
		GameTime(const TimeSpan&, const TimeSpan&);
		GameTime(const TimeSpan&, const TimeSpan&, bool);

		TimeSpan ElapsedGameTime() { return elapsed; }
		bool IsRunningSlow() { return (elapsed > Game::TargetElapsedTime); }
		TimeSpan TotalGameTime() { return total; }

		void ElapsedGameTime(TimeSpan time) { elapsed = time; }
		void TotalGameTime(TimeSpan time) { total = time; }

	private:
		TimeSpan elapsed;
		bool runningSlow;
		TimeSpan total;
	};

	
}
#endif