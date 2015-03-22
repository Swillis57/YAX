#ifndef _VIEWPORT_H
#define _VIEWPORT_H

#include "../../YAX/include/Utils.h"

namespace YAX
{
	class Rectangle;
	class Vector3;
	class Matrix;

	struct Viewport
	{
		Viewport(i32, i32, i32, i32);
		Viewport(Rectangle);

		float AspectRatio();
		void AspectRatio(float);

		Rectangle Bounds();
		void Bounds(Rectangle);

		i32 Height();
		void Height(i32);

		float MaxDepth();
		void MaxDepth(float);

		float MinDepth();
		void MinDepth(float);

		Rectangle TitleSafeArea();

		i32 Width();
		void Width(i32);

		i32 X();
		void X(i32);

		i32 Y();
		void Y(i32);

		Vector3 Project(const Vector3&, const Matrix&, const Matrix&, const Matrix&);
		Vector3 Unproject(const Vector3&, const Matrix&, const Matrix&, const Matrix&);
	};
}


#endif