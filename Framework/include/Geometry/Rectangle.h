#ifndef RECTANGLE
#define RECTANGLE

#include <algorithm>
#include <iostream>
#include "../Utils.h"
#include "Point.h"

namespace XNA
{
	class Rectangle
	{

	public:
		i32 X;
		i32 Y;
		i32 Height;
		i32 Width;

		Rectangle(i32, i32, i32, i32);
		Rectangle(const Rectangle&) = default;
 
		~Rectangle() = default;

		static Rectangle Empty() { return Rectangle(0, 0, 0, 0); }

		i32 Bottom() const;
		Point Center() const;
		bool IsEmpty() const;
		i32 Left() const;
		Point Location() const;
		void Location(const Point&);
		i32 Right() const;
		i32 Top() const;

		bool Contains(const Rectangle&) const;
		bool Contains(const Point&) const;
		void Inflate(i32, i32);
		static Rectangle Intersect(const Rectangle&, const Rectangle&);
		static Rectangle Intersect(const Rectangle&, const Rectangle&, const Rectangle&);
		bool Intersects(const Rectangle&) const;
		void Offset(i32, i32);
		void Offset(const Point&);
		static Rectangle Union(const Rectangle&, const Rectangle&);
		static Rectangle Union(const Rectangle&, const Rectangle&, const Rectangle&);

		Rectangle& operator =(const Rectangle&) = default;

		bool operator ==(const Rectangle&);
		bool operator !=(const Rectangle&);

	};

	Rectangle::Rectangle(i32 x, i32 y, i32 h, i32 w)
		: X(x), Y(y), Height(h), Width(w)
	{}

	i32 Rectangle::Bottom() const
	{
		return (Y + Height);
	}

	Point Rectangle::Center() const
	{
		return Point((X + Width) / 2, (Y + Height) / 2);
	}

	bool Rectangle::IsEmpty() const
	{
		return ((X | Y | Height | Width) == 0);
	}

	i32 Rectangle::Left() const
	{
		return X;
	}

	Point Rectangle::Location() const
	{
		return Point(X, Y);
	}

	void Rectangle::Location(const Point& p)
	{
		X = p.X;
		Y = p.Y;
	}

	i32 Rectangle::Right() const
	{
		return (X + Width);
	}

	i32 Rectangle::Top() const
	{
		return Y;
	}

	bool Rectangle::Contains(const Point& p) const
	{
		return (((p.X >= X) && (p.X <= X + Width)) 
			&& ((p.Y >= Y) && (p.Y <= Y + Height)));
	}

	bool Rectangle::Contains(const Rectangle& r) const
	{
		return Contains(r.Location()) 
			&& (r.Height <= std::abs(Height - r.Y)) 
			&& (r.Width <= std::abs(Width - r.X));
	}

	void Rectangle::Inflate(i32 dw, i32 dh)
	{
		Width += dw;
		Height += dh;
	}

	Rectangle Rectangle::Intersect(const Rectangle& r1, const Rectangle& r2)
	{
		if (!r1.Intersects(r2))
			return Empty();

		i32 left = std::max(r1.X, r2.X);
		i32 right = std::min(r1.X + r1.Width, r2.X + r2.Width);
		i32 top = std::max(r1.Y, r2.Y);
		i32 bottom = std::min(r1.Y + r1.Height, r2.Y + r2.Height);

		return Rectangle(left, top, bottom - top, right - left);
	}

	Rectangle Rectangle::Intersect(const Rectangle& r1, const Rectangle& r2, const Rectangle& r3)
	{
		return Intersect(Intersect(r1, r2), r3);
	}
	
	bool Rectangle::Intersects(const Rectangle& r) const
	{
		Point aCenter = Center();
		Point bCenter = r.Center();

		return (std::abs(aCenter.X - bCenter.X) < (Width + r.Width) / 2) 
			&& (std::abs(aCenter.Y - bCenter.Y) < (Height + r.Height) / 2);
	}

	void Rectangle::Offset(i32 x, i32 y)
	{
		X += x;
		Y += y;
	}

	void Rectangle::Offset(const Point& p)
	{
		X += p.X;
		Y += p.Y;
	}

	Rectangle Rectangle::Union(const Rectangle& r1, const Rectangle& r2)
	{
		i32 top = std::min(r1.Y, r2.Y);
		i32 left = std::min(r1.X, r2.X);
		i32 right = std::max(r1.X + r1.Width, r2.X + r2.Width);
		i32 bottom = std::max(r1.Y + r1.Height, r2.Y + r2.Height);

		return Rectangle(left, top, bottom - top, right - left); 
	}

	Rectangle Rectangle::Union(const Rectangle& r1, const Rectangle& r2, const Rectangle& r3)
	{
		return Union(Union(r1, r2), r3);
	}

	bool Rectangle::operator==(const Rectangle& r)
	{
		return (this->X == r.X
			&& this->Y == r.Y									  
			&& this->Height == r.Height
			&& this->Width == r.Width);
	}

	bool Rectangle::operator!=(const Rectangle& r)
	{
		return !(*this == r);
	}

	std::ostream& operator<<(std::ostream& out, const Rectangle& r)
	{
		return (out << "X:" << r.X << "  Y:" << r.Y << "  Height:" << r.Height << "  Width:" << r.Width);
	}
}



#endif