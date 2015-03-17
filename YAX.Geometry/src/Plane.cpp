#include "../include/Plane.h"

#include "../include/BoundingBox.h"
#include "../include/BoundingFrustum.h"
#include "../include/BoundingSphere.h"
#include "../include/PlaneIntersectionType.h"
#include "../../YAX.Math/include/Vector4.h"

namespace YAX
{
	Plane::Plane()
		: D(0.0f), Normal(Vector3::Zero)
	{}

	Plane::Plane(float x, float y, float z, float d)
		: D(d), Normal(x, y, z)
	{}

	Plane::Plane(const Vector3& normal, float dist)
		: D(dist), Normal(normal)
	{}

	Plane::Plane(const Vector3& p1, const Vector3& p2, const Vector3& p3)
	{
		Vector3 v1 = p2 - p1;
		Vector3 v2 = p3 - p1;

		Vector3 norm = Vector3::Cross(v1, v2);
		norm.Normalize();

		float d = -Vector3::Dot(norm, p1);

		Normal = norm;
		D = d;
	}

	float Plane::Dot(const Vector4& v) const
	{
		Vector4 v4 = Vector4(Normal, D);
		return Vector4::Dot(v4, v);
	}

	float Plane::DotCoordinate(const Vector3& v) const
	{
		return DotNormal(v) + D;
	}

	float Plane::DotNormal(const Vector3& v) const
	{
		return Vector3::Dot(v, Normal);
	}

	PlaneIntersectionType Plane::Intersects(const BoundingBox& bb) const
	{
		return bb.Intersects(*this);
	}

	PlaneIntersectionType Plane::Intersects(const BoundingFrustum& bf) const
	{
		return bf.Intersects(*this);
	}

	PlaneIntersectionType Plane::Intersects(const BoundingSphere& bs) const
	{
		return bs.Intersects(*this);
	}

	Plane Plane::Transform(const Plane& p, const Matrix& m)
	{
		Vector4 v(p.Normal, p.D);
		v = Vector4::Transform(v, Matrix::Transpose(Matrix::Invert(m)));
		return Plane(v.X, v.Y, v.Z, v.W);
	}

	Plane Plane::Transform(const Plane& p, const Quaternion& q)
	{
		Vector3 n = Vector3::Transform(p.Normal, q);
		return Plane(n, p.D);
	}

	bool operator==(const Plane& lhs, const Plane& rhs)
	{
		return lhs.Normal == rhs.Normal && lhs.D == rhs.D;
	}

	bool operator!=(const Plane& lhs, const Plane& rhs)
	{
		return !(lhs == rhs);
	}
}