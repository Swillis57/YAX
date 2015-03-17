#ifndef _POINT_H
#define _POINT_H

#include <iostream>
#include "../../YAX/include/Utils.h"

namespace YAX
{
	struct Point
	{
		static const Point Zero;

		i32 X, Y;

		Point(i32, i32);

	};

	bool operator==(const Point&, const Point&);
	bool operator!=(const Point&, const Point&);

	
}

#endif