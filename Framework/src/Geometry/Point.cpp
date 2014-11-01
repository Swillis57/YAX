#include "../../include/Geometry/Point.h"

namespace XNA
{
	Point::Point(i32 x, i32 y)
		: _x(x), _y(y)
	{}



	bool Point::operator==(const Point& p)
	{
		return (_x == p.X() && _y == p.Y());
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