#ifndef _RAY_H
#define _RAY_H

#include "../Math/Vector3.h"
#include "../Utils.h"
#include "../Nullable.h"

namespace XNA
{
	class BoundingSphere;
	class BoundingBox;
	class BoundingFrustum;
	class Plane;

	struct Ray
	{
		Vector3 Direction, Position;

		Ray(const Vector3&, const Vector3&);
		Nullable<float> Intersects(const BoundingBox&);
		Nullable<float> Intersects(const BoundingFrustum&);
		Nullable<float> Intersects(const BoundingSphere&);
		Nullable<float> Intersects(const Plane&);

		bool operator==(const Ray&);
		bool operator!=(const Ray&);

	};
}


#endif