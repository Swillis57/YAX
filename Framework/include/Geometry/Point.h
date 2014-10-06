#ifndef _POINT_H
#define _POINT_H

#include <iostream>
#include "../Utils.h"

namespace XNA
{
	class Point
	{
	public:
		i32 X;
		i32 Y;

		Point(i32, i32);
		
		static Point Zero() { return Point(0, 0); }
		bool operator==(const Point&);
		bool operator!=(const Point&);
	};

	Point::Point(i32 x, i32 y)
		: X(x), Y(y)
	{}

	bool Point::operator==(const Point& p)
	{
		return (this->X == p.X && this->Y == p.Y);
	}

	bool Point::operator!=(const Point& p)
	{
		return !(*this == p);
	}
	

	std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return (out << "(" << p.X << ", " << p.Y << ")");
	}
}

#endif