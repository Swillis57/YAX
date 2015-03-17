#include "../include/Ray.h"

#include "../include/BoundingBox.h"
#include "../include/BoundingFrustum.h"
#include "../include/BoundingSphere.h"
#include "../include/Plane.h"

namespace YAX
{
	Ray::Ray(const Vector3& position, const Vector3& direction)
		: Pos(position), Dir(direction)
	{}

	std::unique_ptr<float> Ray::Intersects(const BoundingBox& bb)
	{
		return bb.Intersects(*this);
	}

	std::unique_ptr<float> Ray::Intersects(const BoundingFrustum& bf)
	{
		return bf.Intersects(*this);
	}

	std::unique_ptr<float> Ray::Intersects(const BoundingSphere& bs)
	{
		return bs.Intersects(*this);
	}

	std::unique_ptr<float> Ray::Intersects(const Plane& p)
	{
		if (Vector3::Dot(Dir, p.Normal) == 1) return std::unique_ptr<float>();

		float t = -(Vector3::Dot(Pos, p.Normal) + p.D) / (Vector3::Dot(Dir, p.Normal));
		return std::make_unique<float>(t);
	}

	bool operator==(const Ray& lhs, const Ray& rhs)
	{
		return lhs.Pos == rhs.Pos && lhs.Dir == rhs.Dir;
	}

	bool operator!=(const Ray& lhs, const Ray& rhs)
	{
		return !(lhs == rhs);
	}
}