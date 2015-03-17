#ifndef _PLANE_H
#define _PLANE_H

#include "../../YAX.Math/include/Vector3.h"

namespace YAX
{
	struct Vector4;
	struct BoundingBox;
	struct BoundingSphere;
	class BoundingFrustum;

	enum class PlaneIntersectionType : int;

	struct Plane
	{										      
		float D;
		Vector3 Normal;
	
		Plane();
		Plane(float x, float y, float z, float d);
		Plane(const Vector3& normal, float dist);
		Plane(const Vector3& p1, const Vector3& p2, const Vector3& p3);
		Plane(const Vector4&);

		float Dot(const Vector4&) const;
		float DotCoordinate(const Vector3&) const;
		float DotNormal(const Vector3&) const;
		
		PlaneIntersectionType Intersects(const BoundingBox&) const;
		PlaneIntersectionType Intersects(const BoundingSphere&) const;
		PlaneIntersectionType Intersects(const BoundingFrustum&) const;

		static Plane Transform(const Plane&, const Matrix&);
		static Plane Transform(const Plane&, const Quaternion&);

	};
	bool operator==(const Plane&, const Plane&);
	bool operator!=(const Plane&, const Plane&);
}


#endif