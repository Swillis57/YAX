#ifndef _BOUNDING_BOX_H
#define _BOUNDING_BOX_H

#include <array>
#include <memory>
#include "../Math/Vector3.h"
#include "../Utils.h"

namespace YAX
{
	struct Plane;
	struct BoundingSphere;
	class BoundingFrustum;
	struct Ray;
	enum class ContainmentType : int;
	enum class PlaneIntersectionType : int;

	struct BoundingBox
	{
		static const i32 CornerCount = 8;

		BoundingBox(const Vector3&, const Vector3&);
		BoundingBox(const BoundingBox&) = default;
		BoundingBox& operator=(const BoundingBox&) = default;

		Vector3& Min() const;
		void Min(const Vector3&);

		Vector3& Max() const;
		void Max(const Vector3&);
		
		ContainmentType Contains(const BoundingBox&) const;
		ContainmentType Contains(const BoundingFrustum&) const;
		ContainmentType Contains(const BoundingSphere&) const;
		ContainmentType Contains(const Vector3&) const;

		static BoundingBox CreateFromPoints(const std::vector<Vector3>&);
		static BoundingBox CreateFromSphere(const BoundingSphere&);
		static BoundingBox CreateMerged(const BoundingBox&, const BoundingBox&);

		std::array<Vector3, 8> GetCorners() const;
		bool Intersects(const BoundingBox&) const;
		bool Intersects(const BoundingFrustum&) const;
		bool Intersects(const BoundingSphere&) const;
		PlaneIntersectionType Intersects(const Plane&) const;
		std::unique_ptr<float> Intersects(const Ray&) const;

		friend bool operator==(const BoundingBox&, const BoundingBox&);
		friend bool operator!=(const BoundingBox&, const BoundingBox&);

	private:
		Vector3 _min, _max;
	};
}


#endif