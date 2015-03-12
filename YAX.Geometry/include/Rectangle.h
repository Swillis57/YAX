#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <algorithm>
#include <iostream>
#include "../../Framework/include/Utils.h"

namespace YAX
{
	struct Point;

	struct Rectangle
	{

	public:
		static Rectangle Empty();
		static friend Rectangle Intersect(const Rectangle&, const Rectangle&);
		static friend Rectangle Intersect(const Rectangle&, const Rectangle&, const Rectangle&);
		static friend Rectangle Union(const Rectangle&, const Rectangle&);
		static friend Rectangle Union(const Rectangle&, const Rectangle&, const Rectangle&);

		//x, y, w, h
		Rectangle(i32, i32, i32, i32);
		Rectangle(const Rectangle&) = default;
		Rectangle& operator=(const Rectangle&) = default;	

		i32 X() const;
		void X(i32);

		i32 Y() const;
		void Y(i32);

		i32 Height() const;
		void Height(i32);

		i32 Width() const;
		void Width(i32);

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
		bool Intersects(const Rectangle&) const;
		void Offset(i32, i32);
		void Offset(const Point&);

		friend bool operator ==(const Rectangle&, const Rectangle&);
		friend bool operator !=(const Rectangle&, const Rectangle&);

	private:
		i32 _x, _y, _height, _width;

	};

	
}



#endif