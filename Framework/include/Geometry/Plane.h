#ifndef _PLANE_H
#define _PLANE_H

#include "../Math/Vector3.h"

namespace XNA
{
	struct Vector3;
	struct Vector4;
	struct BoundingBox;
	struct BoundingSphere;
	struct BoundingFrustum;

    enum PlaneIntersectionType;

	struct Plane
	{
		float D;
		Vector3 Normal;

		Plane(float, float, float, float);
		Plane(const Vector3&, float);
		Plane(const Vector3&, const Vector3&, const Vector3&);
		Plane(const Vector4&);

		float Dot(const Vector4&);
		float DotCoordinate(const Vector3&);
		float DotNormal(const Vector3&);
		
		PlaneIntersectionType Intersects(const BoundingBox&);
		PlaneIntersectionType Intersects(const BoundingSphere&);
		PlaneIntersectionType Intersects(const BoundingFrustum&);

		static Plane Transform(const Plane&, const Matrix&);
		static Plane Transform(const Plane&, const Quaternion&);

		bool operator=(const Plane&);
		bool operator!=(const Plane&);
	};
}


#endif