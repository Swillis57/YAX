#include "../../include/Geometry/Rectangle.h"

namespace XNA
{
	Rectangle Rectangle::Empty()
	{
		return Rectangle(0, 0, 0, 0); 
	}

	Rectangle::Rectangle(i32 x, i32 y, i32 h, i32 w)
		: _x(x), _y(y), _height(h), _width(w)
	{}

	i32 Rectangle::X() const
	{
		return _x;
	}

	void Rectangle::X(i32 x)
	{
		_x = x;
	}

	i32 Rectangle::Y() const
	{
		return _y;
	}

	void Rectangle::Y(i32 y)
	{
		_y = y;
	}

	i32 Rectangle::Height() const
	{
		return _height;
	}

	void Rectangle::Height(i32 h)
	{
		_height = h;
	}

	i32 Rectangle::Width() const
	{
		return _width;
	}

	void Rectangle::Width(i32 w)
	{
		_width = w;
	}

	i32 Rectangle::Bottom() const
	{
		return (_y + _height);
	}

	Point Rectangle::Center() const
	{
		return Point((_x + _width) / 2, (_y + _height) / 2);
	}

	bool Rectangle::IsEmpty() const
	{
		return ((_x | _y | _height | _width) == 0);
	}

	i32 Rectangle::Left() const
	{
		return _x;
	}

	Point Rectangle::Location() const
	{
		return Point(_x, _y);
	}

	void Rectangle::Location(const Point& p)
	{
		_x = p.X();
		_y = p.Y();
	}

	i32 Rectangle::Right() const
	{
		return (_x + _width);
	}

	i32 Rectangle::Top() const
	{
		return _y;
	}

	bool Rectangle::Contains(const Point& p) const
	{
		return (((p.X() >= _x) && (p.X() <= _x + _width))
			&& ((p.Y() >= _y) && (p.Y() <= _y + _height)));
	}

	bool Rectangle::Contains(const Rectangle& r) const
	{
		return Contains(r.Location())
			&& (r.Height() <= std::abs(_height - r.Y()))
			&& (r.Width() <= std::abs(_width - r.X()));
	}

	void Rectangle::Inflate(i32 dw, i32 dh)
	{
		_width += dw;
		_height += dh;
	}

	Rectangle Intersect(const Rectangle& r1, const Rectangle& r2)
	{
		if (!r1.Intersects(r2))
			return Rectangle::Empty();

		i32 left = std::max(r1.X(), r2.X());
		i32 right = std::min(r1.X() + r1.Width(), r2.X() + r2.Width());
		i32 top = std::max(r1.Y(), r2.Y());
		i32 bottom = std::min(r1.Y() + r1.Height(), r2.Y() + r2.Height());

		return Rectangle(left, top, bottom - top, right - left);
	}

	Rectangle Intersect(const Rectangle& r1, const Rectangle& r2, const Rectangle& r3)
	{
		return Intersect(Intersect(r1, r2), r3);
	}

	bool Rectangle::Intersects(const Rectangle& r) const
	{
		Point aCenter = Center();
		Point bCenter = r.Center();

		return (std::abs(aCenter.X() - bCenter.X()) < (_width + r.Width()) / 2)
			&& (std::abs(aCenter.Y() - bCenter.Y()) < (_height + r.Height()) / 2);
	}

	void Rectangle::Offset(i32 x, i32 y)
	{
		_x += x;
		_y += y;
	}

	void Rectangle::Offset(const Point& p)
	{
		_x += p.X();
		_y += p.Y();
	}

	Rectangle Union(const Rectangle& r1, const Rectangle& r2)
	{
		i32 top = std::min(r1.Y(), r2.Y());
		i32 left = std::min(r1.X(), r2.X());
		i32 right = std::max(r1.X() + r1.Width(), r2.X() + r2.Width());
		i32 bottom = std::max(r1.Y() + r1.Height(), r2.Y() + r2.Height());

		return Rectangle(left, top, bottom - top, right - left);
	}

	Rectangle Union(const Rectangle& r1, const Rectangle& r2, const Rectangle& r3)
	{
		return Union(Union(r1, r2), r3);
	}

	bool operator==(const Rectangle& lhs, const Rectangle& rhs)
	{
		return (lhs._x == rhs._x
			&& lhs._y == rhs._y
			&& lhs._height == rhs._height
			&& lhs._width == rhs._width);
	}

	bool operator!=(const Rectangle& lhs, const Rectangle& rhs)
	{
		return !(lhs == rhs);
	}
}