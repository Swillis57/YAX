#ifndef _POINT_H
#define _POINT_H

#include <iostream>
#include "../Utils.h"

namespace XNA
{
	struct Point
	{
	public:
		static Point Zero();

		Point(i32, i32);
		Point(const Point&) = default;
		Point& operator=(const Point&) = default;

		i32 X() const;
		void X(i32);

		i32 Y() const;
		void Y(i32);

		friend bool operator==(const Point&, const Point&);
		friend bool operator!=(const Point&, const Point&);

	private:
		i32 _x, _y;
	};

	
}

#endif