#ifndef _BOUNDING_FRUSTUM_H
#define _BOUNDING_FRUSTUM_H

#include <array>   
#include <memory>
#include "../../YAX.Math/include/Matrix.h"
#include "Plane.h"
#include "../../YAX/include/Utils.h"

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
		
		YAX::Matrix& Matrix();
		void Matrix(YAX::Matrix);
	
		BoundingFrustum(YAX::Matrix);

		Plane Bottom();
		Plane Far();
		Plane Left();
		Plane Near();
		Plane Right();
		Plane Top();
		
		ContainmentType Contains(const BoundingBox&);
		ContainmentType Contains(BoundingFrustum&);
		ContainmentType Contains(const BoundingSphere&);
		ContainmentType Contains(const Vector3&);

		std::array<Vector3, BoundingFrustum::CornerCount> GetCorners();

		bool Intersects(const BoundingBox&);
		bool Intersects(const BoundingFrustum&);
		bool Intersects(const BoundingSphere&);
		PlaneIntersectionType Intersects(const Plane&);
		std::unique_ptr<float> Intersects(const Ray&);

		friend bool operator==(const BoundingFrustum&, const BoundingFrustum&);
		friend bool operator!=(const BoundingFrustum&, const BoundingFrustum&);

	private:
		std::array<Plane, 6> _planes;
		YAX::Matrix _mat;
		void updatePlanes();
	};
}

#endif