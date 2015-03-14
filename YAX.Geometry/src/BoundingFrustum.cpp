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
		: _mat(m)
	{
		updatePlanes();
		updateCorners();
	}

	YAX::Matrix& BoundingFrustum::Matrix()
	{
		return _mat;
	}

	void BoundingFrustum::Matrix(YAX::Matrix m)
	{
		_mat = m;
		updatePlanes();
		updateCorners();
	}

	void BoundingFrustum::updatePlanes()
	{
		//Store the plane equation coefficients in an array to
		//make handling easier
		Vector4 n[6];
		n[TOP] = { _mat.M14 - _mat.M12,
				   _mat.M24 - _mat.M22,
				   _mat.M34 - _mat.M32,
				   _mat.M44 - _mat.M42 };

		n[BOTTOM] = { _mat.M12 + _mat.M14,
					  _mat.M22 + _mat.M24,
					  _mat.M32 + _mat.M34,
					  _mat.M42 + _mat.M44 };

		n[LEFT] = { _mat.M14 + _mat.M11,
					_mat.M24 + _mat.M21,
					_mat.M34 + _mat.M31,
					_mat.M44 + _mat.M41 };

		n[RIGHT] = { _mat.M14 - _mat.M11,
					 _mat.M24 - _mat.M21,
					 _mat.M34 - _mat.M31,
					 _mat.M44 - _mat.M41 };

		n[FRONT] = { _mat.M13,
					 _mat.M23,
					 _mat.M33,
					 _mat.M43 };

		n[BACK] = { _mat.M14 - _mat.M13,
					_mat.M24 - _mat.M23,
					_mat.M34 - _mat.M33,
					_mat.M44 - _mat.M43 };

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

	void BoundingFrustum::updateCorners()
	{

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

	ContainmentType BoundingFrustum::Contains(const BoundingSphere& bs)
	{
		ContainmentType res = ContainmentType::Contains;
		updatePlanes();

		//For each plane of the frustum
		for (const Plane& p : _planes)
		{								
			float dist = p.DotCoordinate(bs.Center);
			
			//If the distance between the center of the sphere and the plane is 
			//negative and greater than the radius, the sphere does not touch the frustum
			//Else if the distance is positive and less than the radius, the sphere 
			//intersects the frustum
			if (dist <= -bs.Radius)
				return ContainmentType::Disjoint;
			else if (dist <= bs.Radius)
				res = ContainmentType::Intersects;

			return res;
		}
	}

	ContainmentType BoundingFrustum::Contains(const Vector3& v)
	{
		updatePlanes();
		for (const Plane& p : _planes)
		{
			if (p.DotCoordinate(v) < 0)
				return ContainmentType::Disjoint;
		}

		return ContainmentType::Contains;
	}

	std::array<Vector3, BoundingFrustum::CornerCount> BoundingFrustum::GetCorners()
	{
		updatePlanes();
	}
}