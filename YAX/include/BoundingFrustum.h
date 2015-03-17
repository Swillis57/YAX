#ifndef _BOUNDING_FRUSTUM_H
#define _BOUNDING_FRUSTUM_H

#include <array>   
#include <memory>
#include "Matrix.h"
#include "Plane.h"
#include "Utils.h"

namespace YAX
{
	struct Plane;
	struct BoundingBox;
	struct BoundingSphere;
	struct Vector3;
	struct Ray;
	
	enum class ContainmentType : int;
	enum class PlaneIntersectionType : int;

	class BoundingFrustum
	{
	public:
		static const i32 CornerCount = 8;
		
		YAX::Matrix Matrix();
		void Matrix(YAX::Matrix);
	
		BoundingFrustum(YAX::Matrix);

		Plane Bottom() const;
		Plane Far() const;
		Plane Left() const;
		Plane Near() const;
		Plane Right() const;
		Plane Top() const;
		
		ContainmentType Contains(const BoundingBox&) const;
		ContainmentType Contains(const BoundingFrustum&) const;
		ContainmentType Contains(const BoundingSphere&) const;
		ContainmentType Contains(const Vector3&) const;

		std::array<Vector3, BoundingFrustum::CornerCount> GetCorners() const;

		bool Intersects(const BoundingBox&) const;
		bool Intersects(const BoundingFrustum&) const;
		bool Intersects(const BoundingSphere&) const;
		PlaneIntersectionType Intersects(const Plane&) const;
		std::unique_ptr<float> Intersects(const Ray&) const;

		friend bool operator==(const BoundingFrustum&, const BoundingFrustum&);
		friend bool operator!=(const BoundingFrustum&, const BoundingFrustum&);

	private:
		std::array<Plane, 6> _planes;
		std::array<Vector3, 8> _corners;
		YAX::Matrix _mat;

		void updatePlanes();
		void updateCorners();
		Vector3 triplePlaneIntersect(const Plane&, const Plane&, const Plane&);
	};
}

#endif