#ifndef _PLANE_H
#define _PLANE_H

#include "../../Framework.Math/include/Vector3.h"

namespace YAX
{
	struct Vector3;
	struct Vector4;
	struct BoundingBox;
	struct BoundingSphere;
	class BoundingFrustum;

	enum class PlaneIntersectionType : int;

	struct Plane
	{
		Plane(float, float, float, float);
		Plane(const Vector3&, float);
		Plane(const Vector3&, const Vector3&, const Vector3&);
		Plane(const Vector4&);
		Plane(const Plane&) = default;
		Plane& operator=(const Plane&) = default;
												      
		float D;
		Vector3 Normal;

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