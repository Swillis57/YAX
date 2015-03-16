#ifndef _BOUNDING_SPHERE_H
#define _BOUNDING_SPHERE_H

#include <memory>
#include <vector>
#include "PlaneIntersectionType.h"
#include "../../YAX.Math/include/Vector3.h"


namespace YAX
{
	struct BoundingBox;
	struct Matrix;
	struct Ray;
	struct Plane;
	class BoundingFrustum;

	struct BoundingSphere
	{
		Vector3 Center;
		float Radius;
		
		BoundingSphere(const Vector3& center, float radius);

		static BoundingSphere CreateFromBoundingBox(const BoundingBox&);
		static BoundingSphere CreateFromFrustum(const BoundingFrustum&);
		static BoundingSphere CreateFromPoints(const std::vector<Vector3>&);
		static BoundingSphere CreateMerged(const BoundingSphere&, const BoundingSphere&);

		bool Intersects(const BoundingBox&) const;
		bool Intersects(const BoundingFrustum&) const;
		bool Intersects(const BoundingSphere&) const;
		PlaneIntersectionType Intersects(const Plane&) const;
		std::unique_ptr<float> Intersects(const Ray&) const;

		BoundingSphere Transform(const Matrix&) const;
		
	};
	
	bool operator==(const BoundingSphere&, const BoundingSphere&);
	bool operator!=(const BoundingSphere&, const BoundingSphere&);
}

#endif