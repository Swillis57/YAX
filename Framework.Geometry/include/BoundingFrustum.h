#ifndef _BOUNDING_FRUSTUM_H
#define _BOUNDING_FRUSTUM_H

#include <array>   
#include <memory>
#include "../../Framework.Math/include/Matrix.h"
#include "../../Framework/include/Utils.h"

namespace YAX
{
	struct Plane;
	struct BoundingBox;
	class BoundingFrustum;
	struct BoundingSphere;
	struct Vector3;
	struct Ray;
	
	enum ContainmentType;
	enum PlaneIntersectionType;

	class BoundingFrustum
	{
		static const i32 CornerCount = 8;
	
		BoundingFrustum(const YAX::Matrix&);
		BoundingFrustum(const BoundingFrustum&) = default;
		BoundingFrustum& operator=(const BoundingFrustum&) = default;


		YAX::Matrix Matrix() const;
		void Matrix(YAX::Matrix);

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

		std::array<Vector3, 8> GetCorners() const;

		bool Intersects(const BoundingBox&) const;
		bool Intersects(const BoundingFrustum&) const;
		bool Intersects(const BoundingSphere&) const;
		PlaneIntersectionType Intersects(const Plane&) const;
		std::unique_ptr<float> Intersects(const Ray&) const;

		friend bool operator==(const BoundingFrustum&, const BoundingFrustum&);
		friend bool operator!=(const BoundingFrustum&, const BoundingFrustum&);

	private:
		YAX::Matrix _matrix;
	};
}

#endif