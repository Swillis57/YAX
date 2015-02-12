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

}