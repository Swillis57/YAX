#include "../include/BoundingFrustum.h"

#include "../include/BoundingBox.h"
#include "../include/BoundingSphere.h"
#include "../include/ContainmentType.h"
#include "../include/Plane.h"
#include "../include/PlaneIntersectionType.h"
#include "../include/Ray.h"
#include "../../YAX.Math/include/Vector3.h"
#include "../../YAX.Math/include/Vector4.h"

//Plane array indices
#define TOP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3
#define NEAR 4
#define FAR 5

//Corner array indices
#define NEARTOPLEFT 0
#define NEARTOPRIGHT 1
#define NEARBOTRIGHT 2
#define NEARBOTLEFT 3
#define FARTOPLEFT 4
#define FARTOPRIGHT 5
#define FARBOTRIGHT 6
#define FARBOTLEFT 7


namespace YAX
{
	BoundingFrustum::BoundingFrustum(YAX::Matrix m)
		: _mat(m)
	{
		updatePlanes();
		updateCorners();
	}

	YAX::Matrix BoundingFrustum::Matrix()
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

		n[NEAR] = { _mat.M13,
					 _mat.M23,
					 _mat.M33,
					 _mat.M43 };

		n[FAR] = { _mat.M14 - _mat.M13,
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
		_corners[NEARTOPLEFT] = triplePlaneIntersect(_planes[NEAR], _planes[TOP], _planes[LEFT]);
		_corners[NEARTOPRIGHT] = triplePlaneIntersect(_planes[NEAR], _planes[TOP], _planes[RIGHT]);
		_corners[NEARBOTRIGHT] = triplePlaneIntersect(_planes[NEAR], _planes[BOTTOM], _planes[RIGHT]);
		_corners[NEARBOTLEFT] = triplePlaneIntersect(_planes[NEAR], _planes[BOTTOM], _planes[LEFT]);
		_corners[FARTOPLEFT] = triplePlaneIntersect(_planes[FAR], _planes[TOP], _planes[LEFT]);
		_corners[FARTOPRIGHT] = triplePlaneIntersect(_planes[FAR], _planes[TOP], _planes[RIGHT]);
		_corners[FARBOTRIGHT] = triplePlaneIntersect(_planes[FAR], _planes[BOTTOM], _planes[RIGHT]);
		_corners[FARBOTLEFT] = triplePlaneIntersect(_planes[FAR], _planes[BOTTOM], _planes[LEFT]);
	}

	Vector3 BoundingFrustum::triplePlaneIntersect(const Plane& p1, const Plane& p2, const Plane& p3)
	{
		Vector3 p1xp2 = Vector3::Cross(p1.Normal, p2.Normal);
		Vector3 p2xp3 = Vector3::Cross(p2.Normal, p3.Normal);
		Vector3 p3xp1 = Vector3::Cross(p3.Normal, p1.Normal);

		float invDet = 1.0f / Vector3::Dot(p1.Normal, p2xp3);

		return invDet * ((p1.D * p2xp3) + (p2.D * p3xp1) + (p3.D * p1xp2));
	}

	Plane BoundingFrustum::Bottom() const
	{
		return _planes[BOTTOM];
	}

	Plane BoundingFrustum::Far() const
	{
		return _planes[FAR];
	}

	Plane BoundingFrustum::Left() const
	{
		return _planes[LEFT];
	}

	Plane BoundingFrustum::Near() const
	{
		return _planes[NEAR];
	}

	Plane BoundingFrustum::Right() const
	{
		return _planes[RIGHT];
	}

	Plane BoundingFrustum::Top() const
	{
		return _planes[TOP];
	}

	ContainmentType BoundingFrustum::Contains(const BoundingBox& bb) const
	{
		i32 numInside = 0;
		auto corners = bb.GetCorners();

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
				numInside++;

		}

		return (numInside == 6
			? ContainmentType::Contains
			: ContainmentType::Intersects);
	
	}

	ContainmentType BoundingFrustum::Contains(const BoundingFrustum& bf) const
	{
		i32 intersections = 0;
		auto corners = bf.GetCorners();

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

	ContainmentType BoundingFrustum::Contains(const BoundingSphere& bs) const
	{
		ContainmentType res = ContainmentType::Contains;

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
		}
		return res;
	}

	ContainmentType BoundingFrustum::Contains(const Vector3& v) const
	{
		for (const Plane& p : _planes)
		{
			if (p.DotCoordinate(v) < 0)
				return ContainmentType::Disjoint;
		}

		return ContainmentType::Contains;
	}

	std::array<Vector3, BoundingFrustum::CornerCount> BoundingFrustum::GetCorners() const
	{
		return _corners;
	}

	bool BoundingFrustum::Intersects(const BoundingBox& bb) const
	{
		ContainmentType c = Contains(bb);
		return c != ContainmentType::Disjoint;
	}

	bool BoundingFrustum::Intersects(const BoundingFrustum& bf) const
	{
		ContainmentType c = Contains(bf);
		return c != ContainmentType::Disjoint;
	}

	bool BoundingFrustum::Intersects(const BoundingSphere& bs) const
	{
		ContainmentType c = Contains(bs);
		return c != ContainmentType::Disjoint;
	}

	PlaneIntersectionType BoundingFrustum::Intersects(const Plane& p) const
	{
		//true = front, false = back;
		bool frontOrBack = Vector3::Dot(_corners[0], p.Normal) >= 0;

		//If all of the corners of the frustum aren't in the same half-space,
		//then it must intersect the plane
		for (i32 i = 0; i < CornerCount; i++)
		{
			if (Vector3::Dot(_corners[i] , p.Normal) >= 0 != frontOrBack)
				return PlaneIntersectionType::Intersecting;
		}

		return (frontOrBack ? PlaneIntersectionType::Front : PlaneIntersectionType::Back);
	}

	std::unique_ptr<float> BoundingFrustum::Intersects(const Ray& r) const
	{
		if (Contains(r.Pos) == ContainmentType::Contains) 
			return std::make_unique<float>(0.0f);


		for (const Plane& p : _planes)
		{
			float t = -(Vector3::Dot(r.Pos, p.Normal) + p.D) / (Vector3::Dot(r.Dir, p.Normal));
			Vector3 pointOnPlane = r.Pos + t*(r.Dir);

			if (Contains(pointOnPlane) == ContainmentType::Contains)
				return std::make_unique<float>(t);
		}

		return std::make_unique<float>(nullptr);
	}

	bool operator==(const BoundingFrustum& lhs, const BoundingFrustum& rhs)
	{
		return lhs._mat == rhs._mat;
	}

	bool operator!=(const BoundingFrustum& lhs, const BoundingFrustum& rhs)
	{
		return !(lhs == rhs);
	}
}