#include "../../include/Math/Vector4.h"

#include "../../include/Math/Matrix.h"
#include "../../include/Math/MathHelper.h"
#include "../../include/Math/Quaternion.h"
#include "../../include/Math/Vector2.h"
#include "../../include/Math/Vector3.h"

namespace YAX
{
	const Vector4 One = Vector4(1, 1, 1, 1);
	const Vector4 UnitX = Vector4(1, 0, 0, 0);
	const Vector4 UnitY = Vector4(0, 1, 0, 0);
	const Vector4 UnitZ = Vector4(0, 0, 1, 0);
	const Vector4 UnitW = Vector4(0, 0, 0, 1);
	const Vector4 Zero = Vector4(0, 0, 0, 0);

	Vector4::Vector4(float v)
		: X(v), Y(v), Z(v), W(v)
	{}

	Vector4::Vector4(float x, float y, float z, float w)
		: X(x), Y(y), Z(z), W(w)
	{}

	Vector4::Vector4(Vector2 xy, float z, float w)
		: Vector4(xy.X, xy.Y, z, w)
	{}

	Vector4::Vector4(Vector3 xyz, float w)
		: Vector4(xyz.X, xyz.Y, xyz.Z, w)
	{}

	Vector4 Vector4::Barycentric(const Vector4& p1, const Vector4& p2, const Vector4& p3, float b2, float b3)
	{
		return (1 - b2 - b3)*p1 + b2*p2 + b3*p3;
	}

	Vector4 Vector4::CatmullRom(const Vector4& p1, const Vector4& p2, const Vector4& p3, const Vector4& p4, float t)
	{
		return Vector4(MathHelper::CatmullRom(p1.X, p2.X, p3.X, p4.X, t),
					   MathHelper::CatmullRom(p1.Y, p2.Y, p3.Y, p4.Y, t),
					   MathHelper::CatmullRom(p1.Z, p2.Z, p3.Z, p4.Z, t),
					   MathHelper::CatmullRom(p1.W, p2.W, p3.W, p4.W, t));
	}

	Vector4 Vector4::Clamp(const Vector4& val, const Vector4& min, const Vector4& max)
	{
		return Vector4(MathHelper::Clamp(val.X, min.X, max.X),
					   MathHelper::Clamp(val.X, min.X, max.X),
					   MathHelper::Clamp(val.X, min.X, max.X),
					   MathHelper::Clamp(val.X, min.X, max.X));
	}

	float Vector4::Distance(const Vector4& p1, const Vector4& p2)
	{
		return std::sqrtf(DistanceSquared(p1, p2));
	}

	float Vector4::DistanceSquared(const Vector4& p1, const Vector4& p2)
	{
		return (p1 - p2).LengthSquared();
	}

	float Vector4::Dot(const Vector4& v1, const Vector4& v2)
	{
		return (v1.X*v2.X + v1.Y*v2.Y + v1.Z*v2.Z + v1.W*v2.W);
	}

	Vector4 Vector4::Hermite(const Vector4& p1, const Vector4& t1, const Vector4& p2, const Vector4& t2, float amt)
	{
		return Vector4(MathHelper::Hermite(p1.X, t1.X, p2.X, t2.X, amt),
					   MathHelper::Hermite(p1.Y, t1.Y, p2.Y, t2.Y, amt),
					   MathHelper::Hermite(p1.Z, t1.Z, p2.Z, t2.Z, amt),
					   MathHelper::Hermite(p1.W, t1.W, p2.W, t2.W, amt));
	}

	Vector4 Vector4::Lerp(const Vector4& f, const Vector4& to, float t)
	{
		return Vector4(MathHelper::Lerp(f.X, to.X, t),
					   MathHelper::Lerp(f.Y, to.Y, t),
					   MathHelper::Lerp(f.Z, to.Z, t),
					   MathHelper::Lerp(f.W, to.W, t));
	}

	Vector4 Vector4::Max(const Vector4& v1, const Vector4& v2)
	{
		return Vector4(MathHelper::Max(v1.X, v2.X),
					   MathHelper::Max(v1.Y, v2.Y),
					   MathHelper::Max(v1.Z, v2.Z),
					   MathHelper::Max(v1.W, v2.W));
	}

	Vector4 Vector4::Min(const Vector4& v1, const Vector4& v2)
	{
		return Vector4(MathHelper::Min(v1.X, v2.X),
					   MathHelper::Min(v1.Y, v2.Y),
					   MathHelper::Min(v1.Z, v2.Z),
					   MathHelper::Min(v1.W, v2.W));
	}

	Vector4 Vector4::SmoothStep(const Vector4& f, const Vector4& to, float t)
	{
		Vector4(MathHelper::SmoothStep(f.X, to.X, t),
				MathHelper::SmoothStep(f.Y, to.Y, t),
				MathHelper::SmoothStep(f.Z, to.Z, t),
				MathHelper::SmoothStep(f.W, to.W, t));
	}

}