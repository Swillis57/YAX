#include "../include/TimeSpan.h"

namespace YAX
{
	const TimeSpan TimeSpan::Zero(0);
#pragma region Constructors
	
	TimeSpan::TimeSpan(i64 t)
		: ticks(t)
	{}

	TimeSpan::TimeSpan(Ticks&& t)
		: ticks(t.count())
	{}

	TimeSpan::TimeSpan(i64 h, i64 m, i64 s)
		: ticks((h * TicksPerHour) + (m * TicksPerMinute) + (s * TicksPerSecond))
	{}

	TimeSpan::TimeSpan(i64 d, i64 h, i64 m, i64 s)
		: ticks((d * TicksPerDay) + (h * TicksPerHour) + (m * TicksPerMinute) + (s * TicksPerSecond))
	{}

	TimeSpan::TimeSpan(i64 d, i64 h, i64 m, i64 s, i64 millis)
		: ticks((d * TicksPerDay) + (h * TicksPerHour) + (m * TicksPerMinute)
		+ (s * TicksPerSecond) + (millis * TicksPerMillisecond))
	{}
#pragma endregion 

#pragma region Operators
	TimeSpan operator+(const TimeSpan& lhs, const TimeSpan& rhs)
	{
		return TimeSpan(lhs.ticks + rhs.ticks);
	}

	TimeSpan operator-(const TimeSpan& lhs, const TimeSpan& rhs)
	{
		return TimeSpan(lhs.ticks - rhs.ticks);
	}

	TimeSpan operator+=(TimeSpan lhs, const TimeSpan& rhs)
	{
		lhs.ticks += rhs.ticks;
		return lhs;
	}

	TimeSpan operator-=(TimeSpan lhs, const TimeSpan& rhs)
	{
		lhs.ticks -= rhs.ticks;
		return lhs;
	}

	bool operator==(const TimeSpan& lhs, const TimeSpan& rhs)
	{
		return (lhs.ticks == rhs.ticks);
	}

	bool operator>(const TimeSpan& lhs, const TimeSpan& rhs)
	{
		return (lhs.ticks > rhs.ticks);
	}

	bool operator<(const TimeSpan& lhs, const TimeSpan& rhs)
	{
		return (lhs.ticks < rhs.ticks);
	}

	bool operator!=(const TimeSpan& lhs, const TimeSpan& rhs)
	{
		return (lhs.ticks != rhs.ticks);
	}

	bool operator>=(const TimeSpan& lhs, const TimeSpan& rhs)
	{
		return (lhs.ticks >= rhs.ticks);
	}
	bool operator<=(const TimeSpan& lhs, const TimeSpan& rhs)
	{
		return (lhs.ticks <= rhs.ticks);
	}
	TimeSpan TimeSpan::operator-()
	{
		return TimeSpan(-(this->ticks));
	}

#pragma endregion 


	i64 TimeSpan::GetDays()
	{
		return duration_cast<Days>(this->ticks).count();
	}

	i64 TimeSpan::GetHours()
	{
		return duration_cast<hours>(this->ticks).count();
	}

	i64 TimeSpan::GetMilliseconds()
	{
		return duration_cast<milliseconds>(this->ticks).count();
	}

	i64 TimeSpan::GetMinutes()
	{
		return duration_cast<minutes>(this->ticks).count();
	}

	i64 TimeSpan::GetSeconds()
	{
		return duration_cast<seconds>(this->ticks).count();
	}

	i64 TimeSpan::GetTicks()
	{
		return this->ticks.count();
	}

	double TimeSpan::GetTotalDays()
	{
		return (this->ticks.count() / TicksPerDay);
	}

	double TimeSpan::GetTotalHours()
	{
		return (this->ticks.count() / TicksPerHour);
	}

	double TimeSpan::GetTotalMilliseconds()
	{
		return (this->ticks.count() / TicksPerMillisecond);
	}

	double TimeSpan::GetTotalMinutes()
	{
		return (this->ticks.count() / TicksPerMinute);
	}

	double TimeSpan::GetTotalSeconds()
	{
		return (this->ticks.count() / TicksPerSecond);
	}


	TimeSpan TimeSpan::Duration()
	{
		return TimeSpan(this->ticks.count() < 0 ? -this->ticks : this->ticks);
	}

	int TimeSpan::CompareTo(const TimeSpan& ts)
	{
		return (this->ticks < ts.ticks ? -1
			: (this->ticks == ts.ticks ? 0
			: (this->ticks > ts.ticks)));
	}

	string TimeSpan::ToString()
	{
		return std::to_string(this->ticks.count());
	}

	TimeSpan TimeSpan::FromDays(double val)
	{
		double hr = (val - std::floor(val)) * 24;
		double min = (hr - std::floor(hr)) * 60;
		double sec = (min - std::floor(min)) * 60;
		double mil = (sec - std::floor(sec)) * 1000;
		return TimeSpan((i64)val, (i64)hr, (i64)min, (i64)sec, (i64)mil);
	}

	TimeSpan TimeSpan::FromHours(double val)
	{
		double min = (val - std::floor(val)) * 60;
		double sec = (min - std::floor(min)) * 60;
		double mil = (sec - std::floor(sec)) * 1000;
		return TimeSpan(0, (i64)val, (i64)min, (i64)sec, (i64)mil);
	}

	TimeSpan TimeSpan::FromMilliseconds(double val)
	{	
		return TimeSpan(0, 0, 0, 0, (i64)val);
	}
	TimeSpan TimeSpan::FromMinutes(double val)
	{
		double sec = (val - std::floor(val)) * 60;
		double mil = (sec - std::floor(sec)) * 1000;
		return TimeSpan(0, 0, (i64)val, (i64)sec, (i64)mil);
	}

	TimeSpan TimeSpan::FromSeconds(double val)
	{
		double mil = (val - std::floor(val)) * 1000;
		return TimeSpan(0, 0, 0, (i64)val, (i64)mil);
	}
	TimeSpan TimeSpan::FromTicks(i64 val)
	{
		return TimeSpan(val);
	}

}

