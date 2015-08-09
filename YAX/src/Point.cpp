#include "Point.h"

#include <numeric>

namespace YAX
{
	const Point Point::Zero = Point(0, 0);

	Point::Point(i32 x, i32 y)
		: X(x), Y(y)
	{}

	bool operator==(const Point& lhs, const Point& rhs)
	{
		return (lhs.X == rhs.X && lhs.Y == rhs.Y);
	}

	bool operator!=(const Point& lhs, const Point& rhs)
	{
		return !(lhs == rhs);
	}
}