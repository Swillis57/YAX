#ifndef BOUNDING_FRUSTUM
#define BOUNDING_FRUSTUM

#include <array>
#include "../Utils.h"
#include "../Nullable.h"
#include "Plane.h"

namespace XNA
{
	struct Matrix;
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

		Plane Bottom();
		Plane Far();
		Plane Left();
		Plane Near();
		Plane Right();
		Plane Top();
		XNA::Matrix Matrix();
		void Matrix(const XNA::Matrix&);

		ContainmentType Contains(const BoundingBox&);
		ContainmentType Contains(const BoundingFrustum&);
		ContainmentType Contains(const BoundingSphere&);
		ContainmentType Contains(const Vector3&);

		std::array<Vector3, 8> GetCorners();

		bool Intersects(const BoundingBox&);
		bool Intersects(const BoundingFrustum&);
		bool Intersects(const BoundingSphere&);
		PlaneIntersectionType Intersects(const Plane&);
		Nullable<float> Intersects(const Ray&);

		bool operator==(const BoundingFrustum&);
		bool operator!=(const BoundingFrustum&);
	};
}

#endif