#ifndef _BOUNDING_BOX_H
#define _BOUNDING_BOX_H

#include <array>
#include <memory>
#include "Vector3.h"
#include "Utils.h"

namespace YAX
{
	enum class ContainmentType : int;
	enum class PlaneIntersectionType : int;
	
	struct Plane;
	struct BoundingSphere;
	struct Ray;
	class BoundingFrustum;

	struct BoundingBox
	{
		static const i32 CornerCount = 8;

		Vector3 Min, Max;
		
		BoundingBox(Vector3 min, Vector3 max);
		
		ContainmentType Contains(const BoundingBox&) const;
		ContainmentType Contains(const BoundingFrustum&) const;
		ContainmentType Contains(const BoundingSphere&) const;
		ContainmentType Contains(const Vector3&) const;

		static BoundingBox CreateFromPoints(const std::vector<Vector3>& points);
		static BoundingBox CreateFromSphere(const BoundingSphere& sphere);
		static BoundingBox CreateMerged(const BoundingBox& bb1, const BoundingBox& bb2);

		std::array<Vector3, 8> GetCorners() const;
		bool Intersects(const BoundingBox&) const;
		bool Intersects(const BoundingFrustum&) const;
		bool Intersects(const BoundingSphere&) const;
		PlaneIntersectionType Intersects(const Plane&) const;
		std::unique_ptr<float> Intersects(const Ray&) const;

	};

	bool operator==(const BoundingBox&, const BoundingBox&);
	bool operator!=(const BoundingBox&, const BoundingBox&);
}


#endif