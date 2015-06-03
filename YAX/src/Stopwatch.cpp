#include "../include/Stopwatch.h"

#include <chrono>
#include "../include/TimeSpan.h"
#include "../include/Utils.h"

using std::chrono::duration_cast;
using std::chrono::steady_clock;

namespace YAX
{
	Stopwatch::Stopwatch()
		: _elapsed(0),
		_startTime(0),
		_running(false)
	{}		

	i64 Stopwatch::CurrentTimestamp()
	{
		return duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
	}

	TimeSpan Stopwatch::Elapsed()
	{
		i64 elapsed = _elapsed;

		if (_running)
		{
			i64 curTime = CurrentTimestamp();
			i64 delta = curTime - _startTime;
			elapsed += delta;
		}

		return TimeSpan::FromTicks(elapsed / 100);
	}

	i64 Stopwatch::ElapsedMilliseconds()
	{
		return Elapsed().GetTotalMilliseconds();
	}

	i64 Stopwatch::ElapsedTicks()
	{
		return Elapsed().GetTicks();
	}

	void Stopwatch::Start()
	{
		_startTime = CurrentTimestamp();
		_running = true;
	}

	void Stopwatch::Stop()
	{
		_running = false;
		i64 endTime = CurrentTimestamp();
		_elapsed += (endTime - _startTime);
	}

	void Stopwatch::Reset()
	{
		_running = false;
		_elapsed = 0;
		_startTime = 0;
	}

	void Stopwatch::Restart()
	{
		_running = true;
		_elapsed = 0;
		_startTime = CurrentTimestamp();
	}
}