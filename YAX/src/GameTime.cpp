#include "GameTime.h"

namespace YAX
{
	GameTime::GameTime()
		: elapsed(TimeSpan::Zero), runningSlow(false), total(TimeSpan::Zero)
	{}

	GameTime::GameTime(const TimeSpan& elapsedTime, const TimeSpan& totalTime)
		: elapsed(elapsedTime), total(totalTime), runningSlow(false)
	{}

	GameTime::GameTime(const TimeSpan& elapsedTime, const TimeSpan& totalTime, bool slow)
		: elapsed(elapsedTime), total(totalTime), runningSlow(slow)
	{}
}