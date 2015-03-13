#include "../include/BoundingFrustum.h"

#include "../include/BoundingBox.h"
#include "../include/BoundingSphere.h"
#include "../include/ContainmentType.h"
#include "../include/Plane.h"
#include "../include/PlaneIntersectionType.h"
#include "../include/Ray.h"
#include "../../YAX.Math/include/Vector3.h"
#include "../../YAX.Math/include/Vector4.h"

#define TOP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3
#define FRONT 4
#define BACK 5


namespace YAX
{
	BoundingFrustum::BoundingFrustum(YAX::Matrix m)
		: _oldMat(m), Matrix(m)
	{
		updatePlanes();
	}

	void BoundingFrustum::updatePlanes()
	{
		//Matrix hasn't changed, no update needed
		if (Matrix == _oldMat) return;

		_oldMat = Matrix;
		//Store the plane equation coefficients in an array to
		//make handling easier
		Vector4 n[6];
		n[TOP] = { Matrix.M14 - Matrix.M12,
				   Matrix.M24 - Matrix.M22,
				   Matrix.M34 - Matrix.M32,
				   Matrix.M44 - Matrix.M42 };

		n[BOTTOM] = { Matrix.M12 + Matrix.M14,
					  Matrix.M22 + Matrix.M24,
					  Matrix.M32 + Matrix.M34,
					  Matrix.M42 + Matrix.M44 };

		n[LEFT] = { Matrix.M14 + Matrix.M11,
					Matrix.M24 + Matrix.M21,
					Matrix.M34 + Matrix.M31,
					Matrix.M44 + Matrix.M41 };

		n[RIGHT] = { Matrix.M14 - Matrix.M11,
					 Matrix.M24 - Matrix.M21,
					 Matrix.M34 - Matrix.M31,
					 Matrix.M44 - Matrix.M41 };

		n[FRONT] = { Matrix.M13,
					 Matrix.M23,
					 Matrix.M33,
					 Matrix.M43 };

		n[BACK] = { Matrix.M14 - Matrix.M13,
					Matrix.M24 - Matrix.M23,
					Matrix.M34 - Matrix.M33,
					Matrix.M44 - Matrix.M43 };

		for (int i = 0; i < 6; i++)
		{
			Vector4& v = n[i];
			float len = std::sqrtf(v.X*v.X + v.Y*v.Y + v.Z*v.Z);

			//The d coefficient (v.W) of a normalized plane equation is
			//the distance from the origin to the plane
			v /= len;
			_planes[i] = Plane({ v.X, v.Y, v.Z }, v.W);
		}

	}

	Plane BoundingFrustum::Bottom()
	{
		updatePlanes();
		return _planes[BOTTOM];
	}

	Plane BoundingFrustum::Far()
	{
		updatePlanes();
		return _planes[BACK];
	}

	Plane BoundingFrustum::Left()
	{
		updatePlanes();
		return _planes[LEFT];
	}

	Plane BoundingFrustum::Near()
	{
		updatePlanes();
		return _planes[FRONT];
	}

	Plane BoundingFrustum::Right()
	{
		updatePlanes();
		return _planes[RIGHT];
	}

	Plane BoundingFrustum::Top()
	{
		updatePlanes();
		return _planes[TOP];
	}

	ContainmentType BoundingFrustum::Contains(const BoundingBox& bb)
	{
		i32 intersections = 0;
		auto corners = bb.GetCorners();
		updatePlanes();

		for (const Plane& p : _planes)
		{
			i32 inUpperHalfspace = 0;
			for (const Vector3& c : corners)
			{
				if (p.DotCoordinate(c) >= 0)
					inUpperHalfspace++; 
			}

			//If none of the points were in the upper halfspace of the plane,
			//then there's no way the object could be colliding
			if (inUpperHalfspace == 0)
				return ContainmentType::Disjoint;
			else if (inUpperHalfspace == bb.CornerCount)
				intersections++;

		}

		return (intersections == 6
			? ContainmentType::Contains
			: ContainmentType::Intersects);
	
	}

	ContainmentType BoundingFrustum::Contains(BoundingFrustum& bf)
	{
		i32 intersections = 0;
		auto corners = bf.GetCorners();
		updatePlanes();

		for (const Plane& p : _planes)
		{
			i32 inUpperHalfspace = 0;
			for (const Vector3& c : corners)
			{
				if (p.DotCoordinate(c) >= 0)
					inUpperHalfspace++;
			}

			//If none of the points were in the upper halfspace of the plane,
			//then there's no way the object could be colliding
			if (inUpperHalfspace == 0)
				return ContainmentType::Disjoint;
			else if (inUpperHalfspace == bf.CornerCount)
				intersections++;

		}

		return (intersections == 6
			? ContainmentType::Contains
			: ContainmentType::Intersects);
	}

}