#include "../include/BoundingBox.h"

#include <exception>
#include "../include/BoundingFrustum.h"
#include "../include/BoundingSphere.h"
#include "../include/ContainmentType.h"
#include "../include/Plane.h"
#include "../include/PlaneIntersectionType.h"
#include "../../Framework.Math/include/MathHelper.h"
#include "../include/Ray.h"

namespace YAX
{
	BoundingBox::BoundingBox(Vector3 min, Vector3 max)
		: Min(min), Max(max)
	{}

	ContainmentType BoundingBox::Contains(const BoundingBox& bb) const
	{
		if (Intersects(bb))
		{
			if (Min <= bb.Min && Max >= bb.Max)
				return ContainmentType::Contains;
			else
				return ContainmentType::Intersects;
		}
		else
		{
			return ContainmentType::Disjoint;
		}
	}

	ContainmentType BoundingBox::Contains(const BoundingFrustum& bf) const
	{
		auto bfCorners = bf.GetCorners();
		ContainmentType res;
		i32 numIntersects = 0;

		//For each corner of the frustum
		for (const Vector3& v : bfCorners)
		{
			if (Contains(v) == ContainmentType::Contains)
				numIntersects++;
		}

		//If all of the frustum points are inside the box,
		//then the frustum is wholly contained within the box
		//Else handle no intersection and partial intersection cases
		res = (numIntersects == bfCorners.size()
			? ContainmentType::Contains
			: (numIntersects == 0
				? ContainmentType::Disjoint
				: ContainmentType::Intersects));

		return res;
	}

	ContainmentType BoundingBox::Contains(const BoundingSphere& bs) const
	{
		if (!Intersects(bs)) return ContainmentType::Disjoint;

		Vector3 boxCenter = (Max + Min) / 2;
		Vector3 boxToSphere = bs.Center - boxCenter;

		if (bs.Center.X + bs.Radius <= Max.X
			&& bs.Center.X - bs.Radius >= Min.X
			&& bs.Center.Y + bs.Radius <= Max.Y
			&& bs.Center.Y - bs.Radius >= Min.Y
			&& bs.Center.Z + bs.Radius <= Max.Z
			&& bs.Center.Z - bs.Radius >= Min.Z) 
		{
			return ContainmentType::Contains;
		} 
		else
		{
			return ContainmentType::Intersects;
		}
	}

	ContainmentType BoundingBox::Contains(const Vector3& v) const
	{
		if (v >= Min && v <= Max)
			return ContainmentType::Contains;
		else
			return ContainmentType::Disjoint;
	}

	BoundingBox BoundingBox::CreateFromPoints(const std::vector<Vector3>& points)
	{
		if (points.size() == 0) throw std::invalid_argument("CreateFromPoints requires at least one point");

		Vector3 min = Vector3::Zero, max = Vector3::Zero;

		//Find the greatest and least of each coordinate from 
		//the set of points
		for (const Vector3& v : points)
		{
			min.X = MathHelper::Min(min.X, v.X);
			min.Y = MathHelper::Min(min.Y, v.Y);
			min.Z = MathHelper::Min(min.Z, v.Z);
			max.X = MathHelper::Max(max.X, v.X);
			max.Y = MathHelper::Max(max.Y, v.Y);
			max.Z = MathHelper::Max(max.Z, v.Z);
		}

		return BoundingBox(min, max);
	}

	BoundingBox BoundingBox::CreateFromSphere(const BoundingSphere& bs)
	{
		Vector3 r = Vector3(bs.Radius);

		return BoundingBox(bs.Center - r, bs.Center + r);
	}

	BoundingBox BoundingBox::CreateMerged(const BoundingBox& bb1, const BoundingBox& bb2)
	{
		Vector3 min, max;
		
		min.X = MathHelper::Min(bb1.Min.X, bb2.Min.X);
		min.Y = MathHelper::Min(bb1.Min.Y, bb2.Min.Y);
		min.Z = MathHelper::Min(bb1.Min.Z, bb2.Min.Z);

		max.X = MathHelper::Max(bb1.Max.X, bb2.Max.X);
		max.Y = MathHelper::Max(bb1.Max.Y, bb2.Max.Y);
		max.Z = MathHelper::Max(bb1.Max.Z, bb2.Max.Z);

		return BoundingBox(min, max);
	}

	std::array<Vector3, 8> BoundingBox::GetCorners() const
	{
		std::array<Vector3, 8> corners;
		Vector3 diff = Max - Min;

		corners[0] = Min;
		corners[1] = Max;
		corners[2] = Min + Vector3(diff.X, 0, 0);
		corners[3] = Min + Vector3(diff.X, diff.Y, 0);
		corners[4] = Min + Vector3(0, diff.Y, 0);
		corners[5] = Min + Vector3(0, 0, diff.Z);
		corners[6] = Min + Vector3(diff.X, 0, diff.Z);
		corners[7] = Min + Vector3(0, diff.Y, diff.Z);

		return corners;
	}

	bool BoundingBox::Intersects(const BoundingBox& bb) const
	{
		return (Min <= bb.Max && Max >= bb.Min);
	}

	bool BoundingBox::Intersects(const BoundingFrustum& bf) const
	{
		ContainmentType frustumInBox = Contains(bf);
		if (frustumInBox == ContainmentType::Contains 
			|| frustumInBox == ContainmentType::Intersects)
		{
			return true;
		}
		else
		{
			ContainmentType boxInFrustum = bf.Contains(*this);
			return boxInFrustum == ContainmentType::Contains
				|| boxInFrustum == ContainmentType::Intersects;
		}
	}

	bool BoundingBox::Intersects(const BoundingSphere& bs) const
	{
		Vector3 r = Vector3(bs.Radius);

		bool intersectX = Min.X <= (bs.Center.X + r.X) || Max.X >= (bs.Center - r.X);
		bool intersectY = Min.Y <= (bs.Center.Y + r.Y) || Max.Y >= (bs.Center - r.Y);
		bool intersectZ = Min.Z <= (bs.Center.Z + r.Z) || Max.Z >= (bs.Center - r.Z);

		return intersectX && intersectY && intersectZ;
	}

	PlaneIntersectionType BoundingBox::Intersects(const Plane& p) const
	{
		auto corners = GetCorners();
		Vector3 center = (Min + Max) / 2;

		float dot = Vector3::Dot(center, p.Normal);
		if (dot == 0) return PlaneIntersectionType::Intersecting;

		//true = front, false = back or in the plane;
		bool frontOrBack = dot > 0;

		//If all of the corners of the box aren't in the same half-space,
		//then it must intersect the plane
		for (const Vector3& v : corners)
		{
			if (Vector3::Dot(v, p.Normal) > 0 != frontOrBack)
				return PlaneIntersectionType::Intersecting;
		}

		return (dot > 0 ? PlaneIntersectionType::Front : PlaneIntersectionType::Back);
	}

