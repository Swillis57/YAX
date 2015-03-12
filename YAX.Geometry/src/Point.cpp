#include "../include/Point.h"

#include <numeric>

namespace YAX
{
	Point Point::Zero()
	{
		return Point(0, 0);
	}

	Point::Point(i32 x, i32 y)
		: _x(x), _y(y)
	{}

	i32 Point::X() const
	{
		return _x;
	}

	void Point::X(i32 x)
	{
		_x = x;
	}

	i32 Point::Y() const
	{
		return _y;
	}

	void Point::Y(i32 y)
	{
		_y = y;
	}


	bool operator==(const Point& lhs, const Point& rhs)
	{
		return (lhs._x == rhs._x && lhs._y == rhs._y);
	}

	bool operator!=(const Point& lhs, const Point& rhs)
	{
		return !(lhs == rhs);
	}
}