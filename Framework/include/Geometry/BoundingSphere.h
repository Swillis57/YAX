#ifndef _BOUNDING_SPHERE_H
#define _BOUNDING_SPHERE_H

#include <memory>
#include <vector>
#include "PlaneIntersectionType.h"
#include "../Math/Vector3.h"


namespace XNA
{
	class BoundingBox;
	class BoundingFrustum;
	class Matrix;
	class Ray;
	class Plane;

	struct BoundingSphere
	{
		BoundingSphere(const Vector3&, float);
		BoundingSphere(const BoundingSphere&) = default;
		BoundingSphere& operator=(const BoundingSphere&) = default;

		Vector3 Center() const;
		void Center(const Vector3&);

		float Radius() const;
		void Radius(float);

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
		
		friend bool operator==(const BoundingSphere&, const BoundingSphere&);
		friend bool operator!=(const BoundingSphere&, const BoundingSphere&);

	private:
		Vector3 _center;
		float _radius;

	};
}

#endif