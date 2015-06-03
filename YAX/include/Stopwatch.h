#ifndef _STOPWATCH_H
#define _STOPWATCH_H

namespace YAX
{
	struct TimeSpan;

	class Stopwatch
	{
	public:
		Stopwatch();

		i64 CurrentTimestamp();
		TimeSpan Elapsed();
		i64 ElapsedMilliseconds();
		i64 ElapsedTicks();
		bool IsRunning();

		void Start();
		void Stop();
		void Reset();
		void Restart();

	private:
		i64 _startTime;
		i64 _elapsed;
		bool _running;
	};
}
#endif