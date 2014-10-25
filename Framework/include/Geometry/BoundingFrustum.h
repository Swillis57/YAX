#ifndef _BOUNDING_FRUSTUM_H
#define _BOUNDING_FRUSTUM_H

#include <array>
#include "../Utils.h"
#include <memory>
#include "../Math/Matrix.h"

namespace XNA
{
	struct Plane;
	struct BoundingBox;
	struct BoundingFrustum;
	struct BoundingSphere;
	struct Vector3;
	struct Ray;
	
	enum ContainmentType;
	enum PlaneIntersectionType;

	struct BoundingFrustum
	{
		const i32 CornerCount = 8;
	
		BoundingFrustum(const Matrix&);

		XNA::Matrix Matrix();
		void Matrix(XNA::Matrix);

		Plane Bottom();
		Plane Far();
		Plane Left();
		Plane Near();
		Plane Right();
		Plane Top();
		
		ContainmentType Contains(const BoundingBox&);
		ContainmentType Contains(const BoundingFrustum&);
		ContainmentType Contains(const BoundingSphere&);
		ContainmentType Contains(const Vector3&);

		const std::array<Vector3, 8>& GetCorners();

		bool Intersects(const BoundingBox&);
		bool Intersects(const BoundingFrustum&);
		bool Intersects(const BoundingSphere&);
		PlaneIntersectionType Intersects(const Plane&);
		std::unique_ptr<float> Intersects(const Ray&);

		bool operator==(const BoundingFrustum&);
		bool operator!=(const BoundingFrustum&);

	private:
		std::array<Vector3, 8> _corners;
		XNA::Matrix _matrix;
	};
}

#endif