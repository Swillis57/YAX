#ifndef _GAME_TIME_H
#define _GAME_TIME_H

#include "Game.h"
#include "TimeSpan.h"

namespace YAX
{
	

	class GameTime
	{
	public:
		GameTime();
		GameTime(const TimeSpan&, const TimeSpan&);
		GameTime(const TimeSpan&, const TimeSpan&, bool);

		TimeSpan& ElapsedGameTime() { return elapsed; }
		bool IsRunningSlow() { return runningSlow; }
		TimeSpan& TotalGameTime() { return total; }

		void ElapsedGameTime(TimeSpan time) { elapsed = time; }
		void IsRunningSlow(bool b) { runningSlow = b; }
		void TotalGameTime(TimeSpan time) { total = time; }

	private:
		TimeSpan elapsed;
		bool runningSlow;
		TimeSpan total;
	};

	
}
#endif