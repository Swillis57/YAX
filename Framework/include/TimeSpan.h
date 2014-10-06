#ifndef _TIME_SPAN_H
#define _TIME_SPAN_H

#include <string>
#include <iostream>
#include <chrono>
#include "Utils.h"

using std::string;
using namespace std::chrono;

namespace XNA
{
	typedef duration<i64, std::ratio<1, 10000000>> Ticks;
	typedef duration<i32, std::ratio<3600, 1>> Days;
	

	class TimeSpan
	{
	

	public:
		
		
		static const i64 TicksPerMillisecond = 10000;
		static const i64 TicksPerSecond = TicksPerMillisecond * 1000;
		static const i64 TicksPerMinute = TicksPerSecond * 60;
		static const i64 TicksPerHour = TicksPerMinute * 60;
		static const i64 TicksPerDay = TicksPerHour * 24;
		static const i64 MaxTicks = 9223372036854775807LL;
		static const i64 MinTicks = -9223372036854775808LL;
		


		TimeSpan(const Ticks&);
		TimeSpan(Ticks&&);
		TimeSpan(i64);
		TimeSpan(i64, i64, i64);
		TimeSpan(i64, i64, i64, i64);
		TimeSpan(i64, i64, i64, i64, i64);
		


		friend TimeSpan operator+(const TimeSpan&, const TimeSpan&);
		friend TimeSpan operator-(const TimeSpan&, const TimeSpan&);
		friend bool operator==(const TimeSpan&, const TimeSpan&);
		friend bool operator>(const TimeSpan&, const TimeSpan&);
		friend bool operator<(const TimeSpan&, const TimeSpan&);
		friend bool operator!=(const TimeSpan&, const TimeSpan&);
		friend bool operator>=(const TimeSpan&, const TimeSpan&);
		friend bool operator<=(const TimeSpan&, const TimeSpan&);
		TimeSpan operator-();



		i64 GetDays();
		i64 GetHours();
		i64 GetMilliseconds();
		i64 GetMinutes();
		i64 GetSeconds();
		i64 GetTicks();
		double GetTotalDays();
		double GetTotalHours();
		double GetTotalMilliseconds();
		double GetTotalMinutes();
		double GetTotalSeconds();



		TimeSpan Duration();
		int CompareTo(const TimeSpan&);
		std::string ToString();



		static TimeSpan FromDays(double);
		static TimeSpan FromHours(double);
		static TimeSpan FromMilliseconds(double);
		static TimeSpan FromMinutes(double);
		static TimeSpan FromSeconds(double);
		static TimeSpan FromTicks(i64);

		static const TimeSpan Zero;
	private:
		Ticks ticks;
		

	};
	
}

#endif

