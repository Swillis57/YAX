#include "../include/BoundingSphere.h"

#include <exception>
#include "../include/BoundingBox.h"
#include "../include/BoundingFrustum.h"
#include "../include/Ray.h"
#include "../include/Plane.h"
#include "../../YAX.Math/include/MathHelper.h"
#include "../../YAX.Math/include/Matrix.h"

namespace YAX
{
	BoundingSphere::BoundingSphere(const Vector3& center, float rad)
		: Center(center), Radius(rad)
	{}

	BoundingSphere BoundingSphere::CreateFromBoundingBox(const BoundingBox& bb)
	{
		Vector3 center = (bb.Min + bb.Max) / 2.0f;
		float r = (bb.Max - center).Length();

		return BoundingSphere(center, r);
	}

	BoundingSphere BoundingSphere::CreateFromFrustum(const BoundingFrustum& bf)
	{
		auto corners = bf.GetCorners();
		return CreateFromPoints({ corners.begin(), corners.end() });
	}

	BoundingSphere BoundingSphere::CreateFromPoints(const std::vector<Vector3>& points)
	{
		if (points.size() == 0) throw std::invalid_argument("Points vector must not be empty");

		//Find the center of the group by averaging the points
		Vector3 center;
		for (const Vector3& v : points)
			center += v;		
		center /= static_cast<float>(points.size());

		//Then find the maximum distance from a point to the avg. center
		//this is the radius
		float maxDist = (points[0] - center).LengthSquared();
		for (size_t i = 1; i < points.size(); i++)
		{
			maxDist = MathHelper::Max(maxDist, (points[i] - center).LengthSquared());
		}

		return BoundingSphere(center, std::sqrtf(maxDist));
	}

	BoundingSphere BoundingSphere::CreateMerged(const BoundingSphere& bs1, const BoundingSphere& bs2)
	{
		Vector3 center = (bs1.Center + bs2.Center) / 2.0f;
		float r = bs1.Radius + (center - bs1.Center).Length();

		return BoundingSphere(center, r);
	}

	bool BoundingSphere::Intersects(const BoundingBox& bb) const
	{
		return bb.Intersects(*this);
	}
	
	bool BoundingSphere::Intersects(const BoundingFrustum& bf) const
	{
		return bf.Intersects(*this);
	}
	
	bool BoundingSphere::Intersects(const BoundingSphere& bs) const
	{
		return (Center - bs.Center).LengthSquared() < Radius * Radius + bs.Radius * bs.Radius;
	}

	PlaneIntersectionType BoundingSphere::Intersects(const Plane& p) const
	{
		Vector3 closestToPlane = Center + (p.Normal*Radius);
		
		//Distance from center of sphere to plane
		float cDot = p.DotCoordinate(Center);
		//Distance from closest point on sphere to plane
		float ctpDot = p.DotCoordinate(closestToPlane);

		//If the two distances are of opposite signs, or either one is zero, the sphere 
		//intersects the plane
		//Else no intersection
		if ((cDot > 0 && ctpDot < 0) || (cDot < 0 && ctpDot > 0) || cDot == 0 || ctpDot == 0)
			return PlaneIntersectionType::Intersecting;
		else
			return (cDot > 0 ? PlaneIntersectionType::Front : PlaneIntersectionType::Back);
	}

	std::unique_ptr<float> BoundingSphere::Intersects(const Ray& r) const
	{
		Vector3 rayToSphere = Center - r.Pos;
		float l = Vector3::Dot(r.Dir, rayToSphere);
		Vector3 proj = r.Dir * l;

		//If the center of the sphere is behind the ray
		if (l < 0)
		{
			float dist = rayToSphere.LengthSquared();		

			//If the ray's origin is outside the sphere, no collision
			//Else if it's on the radius, return 0 dist
			//Else it's inside the sphere so find the point of intersection
			if (dist > Radius * Radius)
				return std::unique_ptr<float>();
			else if (dist == Radius)
				return std::make_unique<float>(0.0f);
			else
			{
				float d = std::sqrtf(Radius*Radius - (proj - Center).LengthSquared());
				float t = d - (proj - r.Pos).Length();
				return std::make_unique<float>(t);
			}
		}
		else //The center of the sphere is in front of the ray 
		{
			//If the center's projection onto the ray is outside of the radius, no collision
			//Else find the point of contact closest to the ray's origin
			if ((proj - Center).LengthSquared() > Radius*Radius)
				return std::unique_ptr<float>();
			else
			{
				float d = std::sqrtf(Radius*Radius - (proj - Center).LengthSquared());
				float t = (proj - r.Pos).Length();
				t += (l > Radius*Radius ? -d : d);
				return std::make_unique<float>(t);
			}
		}
	}

	BoundingSphere BoundingSphere::Transform(const Matrix& m) const
	{
		Vector3 center = Vector3::Transform(Center, m);
		float scale = std::sqrtf(m.M11*m.M11 + m.M12*m.M12 + m.M13*m.M13);

		return BoundingSphere(center, scale);
	}

	bool operator==(const BoundingSphere& lhs, const BoundingSphere& rhs)
	{
		return lhs.Center == rhs.Center && lhs.Radius == rhs.Radius;
	}
}