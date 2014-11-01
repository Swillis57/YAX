#ifndef _BOUNDING_BOX_H
#define _BOUNDING_BOX_H

#include <array>
#include "../Math/Vector3.h"
#include "../Utils.h"
#include <memory>

namespace XNA
{
	struct Plane;
	struct BoundingSphere;
	struct BoundingFrustum;
	struct Ray;
	enum class ContainmentType;
	enum class PlaneIntersectionType;

	struct BoundingBox
	{
		const i32 CornerCount = 8;
		Vector3 Max;
		Vector3 Min;

		BoundingBox(const Vector3&, const Vector3&);
		
		ContainmentType Contains(const BoundingBox&);
		ContainmentType Contains(const BoundingFrustum&);
		ContainmentType Contains(const BoundingSphere&);
		ContainmentType Contains(const Vector3&);

		static BoundingBox CreateFromPoints(const std::vector<Vector3>&);
		static BoundingBox CreateFromSphere(const BoundingSphere&);
		static BoundingBox CreateMerged(const BoundingBox&, const BoundingBox&);

		std::array<Vector3, 8> GetCorners();
		bool Intersects(const BoundingBox&);
		bool Intersects(const BoundingFrustum&);
		bool Intersects(const BoundingSphere&);
		PlaneIntersectionType Intersects(const Plane&);
		std::unique_ptr<float> Intersects(const Ray&);

		bool operator=(const BoundingBox&);
		bool operator!=(const BoundingBox&);
	};
}


#endif