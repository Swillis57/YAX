#include "../../include/Math/Quaternion.h"

#include "../../include/Math/MathHelper.h" 
#include "../../include/Math/Matrix.h"
#include "../../include/Math/Vector3.h"

namespace YAX
{
	const Quaternion Quaternion::Identity(0, 0, 0, 1.0f);

	Quaternion::Quaternion(float x, float y, float z, float w)
		: X(x), Y(y), Z(z), W(w)
	{}

	Quaternion::Quaternion(Vector3 xyz, float w)
		: Quaternion(xyz.X, xyz.Y, xyz.Z, w)
	{}

	void Quaternion::Conjugate()
	{
		X = -X;
		Y = -Y;
		Z = -Z;
	}

	float Quaternion::Dot(const Quaternion& q) const
	{
		return X*q.X + Y*q.Y + Z*q.Z + W*q.W;
	}

	float Quaternion::Length() const
	{
		return std::sqrt(LengthSquared());
	}

	float Quaternion::LengthSquared() const
	{
		return X*X + Y*Y + Z*Z + W*W;
	}

	void Quaternion::Normalize()
	{
		float len = Length();
		X /= len;
		Y /= len;
		Z /= len;
		W /= len;
	}
}
