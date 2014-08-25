#ifndef BOUNDING_SPHERE
#define BOUNDING_SPHERE

#include "../Math/Vector3.h"
#include "PlaneIntersectionType.h"
#include "../Nullable.h"

namespace XNA
{
	template<>
	class std::vector<Vector3>;

	class BoundingBox;
	class BoundingFrustum;
	class Matrix;
	class Ray;
	class Plane;

	struct BoundingSphere
	{
		Vector3 Center;
		float Radius;

		BoundingSphere(const Vector3&, float);

		static BoundingSphere CreateFromBoundingBox(const BoundingBox&);
		static BoundingSphere CreateFromFrustum(const BoundingFrustum&);
		static BoundingSphere CreateFromPoints(const std::vector<Vector3>&);
		static BoundingSphere CreateMerged(const BoundingSphere&, const BoundingSphere&);

		bool Intersects(const BoundingBox&);
		bool Intersects(const BoundingFrustum&);
		bool Intersects(const BoundingSphere&);
		PlaneIntersectionType Intersects(const Plane&);
		Nullable<float> Intersects(const Ray&);

		BoundingSphere Transform(const Matrix&);
		
		bool operator==(const BoundingSphere&);
		bool operator!=(const BoundingSphere&);

	};
}

#endif