#include "../include/Vector3.h"

#include <cmath>
#include "../include/MathHelper.h"
#include "../include/Matrix.h"
#include "../include/Quaternion.h"
#include "../include/Vector2.h"

namespace YAX
{	
	const Vector3 Vector3::One = Vector3(1.0f);
	const Vector3 Vector3::UnitX = Vector3(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::UnitY = Vector3(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::UnitZ = Vector3(0.0f, 0.0f, 1.0f);
	const Vector3 Vector3::Backward = Vector3::UnitZ;
	const Vector3 Vector3::Down = -Vector3::UnitY;
	const Vector3 Vector3::Forward = -Vector3::UnitZ;
	const Vector3 Vector3::Left = -Vector3::UnitX;
	const Vector3 Vector3::Right = Vector3::UnitX;
	const Vector3 Vector3::Up = Vector3::UnitY;

	Vector3::Vector3() = default;

	Vector3::Vector3(float val)
		: X(val), Y(val), Z(val)
	{}

	Vector3::Vector3(float x, float y, float z)
		: X(x), Y(y), Z(z)
	{}

	Vector3::Vector3(Vector2 xy, float z)
		: X(xy.X), Y(xy.Y), Z(z)
	{}

	void Vector3::Normalize()
	{
		float len = Length();
		X /= len;
		Y /= len;
		Z /= len;
	}

	float Vector3::Length()	const
	{
		return std::sqrt(LengthSquared());
	}

	float Vector3::LengthSquared() const
	{
		return X*X + Y*Y + Z*Z;
	}

	Vector3 Vector3::Barycentric(const Vector3& p1, const Vector3& p2, const Vector3& p3, float b2, float b3)
	{
		return (1 - b2 - b3)*p1 + b2*p2 + b3*p3;
	}

	Vector3 Vector3::CatmullRom(const Vector3& p1, const Vector3& p2, const Vector3& p3, const Vector3& p4, float amt)
	{
		float x = MathHelper::CatmullRom(p1.X, p2.X, p3.X, p4.X, amt);
		float y = MathHelper::CatmullRom(p1.Y, p2.Y, p3.Y, p4.Y, amt);
		float z = MathHelper::CatmullRom(p1.Z, p2.Z, p3.Z, p4.Z, amt);
	
		return Vector3(x, y, z);
	}

	Vector3 Vector3::Clamp(const Vector3& val, const Vector3& min, const Vector3& max)
	{
		float x = MathHelper::Clamp(val.X, min.X, max.X);
		float y = MathHelper::Clamp(val.Y, min.Y, max.Y);
		float z = MathHelper::Clamp(val.Z, min.Z, max.Z);

		return Vector3(x, y, z);
	}

	Vector3 Vector3::Cross(const Vector3& v1, const Vector3 v2)
	{
		float x = v1.Y*v2.Z - v1.Z*v2.Y;
		float y = v1.Z*v2.X - v1.X*v2.Z;
		float z = v1.X*v2.Y - v1.Y*v2.X;
		return Vector3(x, y, z);
	}

	float Vector3::Distance(const Vector3& p1, const Vector3& p2)
	{
		return std::sqrt(DistanceSquared(p1, p2));
	}

	float Vector3::DistanceSquared(const Vector3& p1, const Vector3& p2)
	{
		return (p1 - p2).LengthSquared();
	}

	float Vector3::Dot(const Vector3& v1, const Vector3& v2)
	{
		return v1.X*v2.X + v1.Y*v2.Y + v1.Z*v2.Z;
	}

	Vector3 Vector3::Hermite(const Vector3& p1, const Vector3& t1, const Vector3& p2, const Vector3& t2, float w)
	{
		float x = MathHelper::Hermite(p1.X, t1.X, p2.X, t2.X, w);
		float y = MathHelper::Hermite(p1.Y, t1.Y, p2.Y, t2.Y, w);
		float z = MathHelper::Hermite(p1.Z, t1.Z, p2.Z, t2.Z, w);

		return Vector3(x, y, z);
	}

	Vector3 Vector3::Max(const Vector3& v1, const Vector3& v2)
	{
		float x = MathHelper::Max(v1.X, v2.X);
		float y = MathHelper::Max(v1.Y, v2.Y);
		float z = MathHelper::Max(v1.Z, v2.Z);

		return Vector3(x, y, z);
	}

	Vector3 Vector3::Min(const Vector3& v1, const Vector3& v2)
	{
		float x = MathHelper::Min(v1.X, v2.X);
		float y = MathHelper::Min(v1.Y, v2.Y);
		float z = MathHelper::Min(v1.Z, v2.Z);

		return Vector3(x, y, z);
	}

	Vector3 Vector3::Normalize(Vector3 vec)
	{
		vec.Normalize();
		return vec;
	}

	Vector3 Vector3::Reflect(const Vector3& vec, const Vector3& norm)
	{
		Vector3 projection = Dot(vec, norm) * norm;
		Vector3 perp = projection - vec;
		return vec + 2 * perp;
	}

	Vector3 Vector3::SmoothStep(const Vector3& a, const Vector3& b, float t)
	{
		float x = MathHelper::SmoothStep(a.X, b.X, t);
		float y = MathHelper::SmoothStep(a.Y, b.Y, t);
		float z = MathHelper::SmoothStep(a.Z, b.Z, t);

		return Vector3(x, y, z);
	}

	Vector3 Vector3::Transform(const Vector3& vec, const Matrix& mat)
	{
		return Vector3
		(
			vec.X*mat.M11 + vec.Y*mat.M21 + vec.Z*mat.M31 + mat.M41,
			vec.X*mat.M12 + vec.Y*mat.M22 + vec.Z*mat.M32 + mat.M42,
			vec.X*mat.M13 + vec.Y*mat.M23 + vec.Z*mat.M33 + mat.M41
		);
	}

	Vector3 Vector3::Transform(const Vector3& vec, const Quaternion& q)
	{
		Quaternion vQ(0, vec.X, vec.Y, vec.Z);
		Quaternion res = q * vQ * Quaternion::Conjugate(q);
		return Vector3(res.X, res.Y, res.Z);
	}

	void Vector3::Transform(const std::vector<Vector3>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector3>& dest, i32 destIdx, i32 count)
	{
		for (auto i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = Vector3::Transform(source[i], mat);
		}
	}

	void Vector3::Transform(const std::vector<Vector3>& source, i32 sourceIdx, const Quaternion& q, std::vector<Vector3>& dest, i32 destIdx, i32 count)
	{
		for (auto i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = Vector3::Transform(source[i], q);
		}
	}

	void Vector3::Transform(const std::vector<Vector3>& source, const Matrix& mat, std::vector<Vector3>& dest)
	{
		Transform(source, 0, mat, dest, 0, source.size());
	}

	void Vector3::Transform(const std::vector<Vector3>& source, const Quaternion& q, std::vector<Vector3>& dest)
	{
		Transform(source, 0, q, dest, 0, source.size());
	}

	Vector3 Vector3::TransformNormal(const Vector3& norm, const Matrix& mat)
	{
		return Vector3
		(
			norm.X*mat.M11 + norm.Y*mat.M21 + norm.Z*mat.M31,
			norm.X*mat.M12 + norm.Y*mat.M22 + norm.Z*mat.M32,
			norm.X*mat.M13 + norm.Y*mat.M23 + norm.Z*mat.M33
		);
	}

	void Vector3::TransformNormal(const std::vector<Vector3>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector3>& dest, i32 destIdx, i32 count)
	{
		for (auto i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = TransformNormal(source[i], mat);
		}
	}

	void Vector3::TransformNormal(const std::vector<Vector3>& source, const Matrix& mat, std::vector<Vector3>& dest)
	{
		TransformNormal(source, 0, mat, dest, 0, source.size());
	}

	Vector3& Vector3::operator+=(const Vector3& v)
	{
		this->X += v.X;
		this->Y += v.Y;
		this->Z += v.Z;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& v)
	{
		this->X -= v.X;
		this->Y -= v.Y; 
		this->Z -= v.Z;
		return *this;
	}

	Vector3& Vector3::operator*=(const Vector3& v)
	{
		this->X *= v.X;
		this->Y *= v.Y;
		this->Z *= v.Z;
		return *this;
	}

	Vector3& Vector3::operator*=(float s)
	{
		this->X *= s;
		this->Y *= s;
		this->Z *= s;
		return *this;
	}

	Vector3& Vector3::operator/=(const Vector3& v)
	{
		this->X /= v.X;
		this->Y /= v.Y;
		this->Z /= v.Z;
		return *this;
	}

	Vector3& Vector3::operator/=(float s)
	{
		this->X /= s;
		this->Y /= s;
		this->Z /= s;
		return *this;
	}

	Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3
		(
			lhs.X + rhs.X,
			lhs.Y + rhs.Y,
			lhs.Z + rhs.Z
		);
	}

	Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs + (-rhs);
	}

	Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3
		(
			lhs.X * rhs.X,
			lhs.Y * rhs.Y,
			lhs.Z * rhs.Z
		);
	}

	Vector3 operator*(const Vector3& lhs, float rhs)
	{
		return Vector3
		(
			lhs.X * rhs,
			lhs.Y * rhs,
			lhs.Z * rhs
		);
	}

	Vector3 operator*(float lhs, const Vector3& rhs)
	{
		return rhs * lhs;
	}

	Vector3 operator/(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3
		(
			lhs.X / rhs.X,
			lhs.Y / rhs.Y,
			lhs.Z / rhs.Z
		);
	}

	Vector3 operator/(const Vector3& lhs, float rhs)
	{
		return Vector3
		(
			lhs.X / rhs,
			lhs.Y / rhs,
			lhs.Z / rhs
		);
	}

	Vector3 operator-(const Vector3& rhs)
	{
		return Vector3
		(
			-rhs.X,
			-rhs.Y,
			-rhs.Z
		);
	}

	bool operator==(const Vector3& lhs, const Vector3& rhs)
	{
		return (lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z);
	}

	bool operator!=(const Vector3& lhs, const Vector3& rhs)
	{
		return !(lhs == rhs);
	}

	bool operator>(const Vector3& lhs, const Vector3& rhs)
	{
		return (lhs.X > rhs.X && lhs.Y > rhs.Y && lhs.Z > rhs.Z);
	}

	bool operator<(const Vector3& lhs, const Vector3& rhs)
	{
		return (lhs.X < rhs.X && lhs.Y < rhs.Y && lhs.Z < rhs.Z);
	}

	bool operator>=(const Vector3& lhs, const Vector3& rhs)
	{
		return (lhs.X >= rhs.X && lhs.Y >= rhs.Y && lhs.Z >= rhs.Z);
	}

	bool operator<=(const Vector3& lhs, const Vector3& rhs)
	{
		return (lhs.X <= rhs.X && lhs.Y <= rhs.Y && lhs.Z <= rhs.Z);
	}
}

