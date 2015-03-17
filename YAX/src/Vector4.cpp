#include "../include/Vector4.h"

#include "../include/Matrix.h"
#include "../include/MathHelper.h"
#include "../include/Quaternion.h"
#include "../include/Vector2.h"
#include "../include/Vector3.h"

namespace YAX
{
	const Vector4 One = Vector4(1, 1, 1, 1);
	const Vector4 UnitX = Vector4(1, 0, 0, 0);
	const Vector4 UnitY = Vector4(0, 1, 0, 0);
	const Vector4 UnitZ = Vector4(0, 0, 1, 0);
	const Vector4 UnitW = Vector4(0, 0, 0, 1);
	const Vector4 Zero = Vector4(0, 0, 0, 0);

	Vector4::Vector4()
		: Vector4(0.0f)
	{}

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

	void Vector4::Normalize()
	{
		*this /= this->Length();
	}

	float Vector4::Length()
	{
		return std::sqrtf(LengthSquared());
	}

	float Vector4::LengthSquared()
	{
		return X*X + Y*Y + Z*Z + W*W;
	}

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

	Vector4 Vector4::Normalize(Vector4 v)
	{
		v.Normalize();
		return v;
	}

	Vector4 Vector4::SmoothStep(const Vector4& f, const Vector4& to, float t)
	{
		return Vector4(MathHelper::SmoothStep(f.X, to.X, t),
					   MathHelper::SmoothStep(f.Y, to.Y, t),
					   MathHelper::SmoothStep(f.Z, to.Z, t),
					   MathHelper::SmoothStep(f.W, to.W, t));
	}

	Vector4 Vector4::Transform(const Vector4& v, const Matrix& m)
	{
		float x = v.X*m.M11 + v.Y*m.M21 + v.Z*m.M31 + v.W*m.M41;
		float y = v.X*m.M12 + v.Y*m.M22 + v.Z*m.M32 + v.W*m.M42;
		float z = v.X*m.M13 + v.Y*m.M23 + v.Z*m.M33 + v.W*m.M43;
		float w = v.X*m.M14 + v.Y*m.M24 + v.Z*m.M34 + v.W*m.M44;

		return Vector4(x, y, z, w);
	}

	Vector4 Vector4::Transform(const Vector4& v, const Quaternion& q)
	{
		Quaternion vQ(v.X, v.Y, v.Z, v.W);
		Quaternion res = q*vQ*Quaternion::Inverse(q);
		
		return Vector4(res.X, res.Y, res.Z, res.W);
	}

	void Vector4::Transform(const std::vector<Vector4>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector4>& dest, i32 destIdx, i32 count)
	{
		for (i32 i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = Transform(source[i], mat);
		}
	}

	void Vector4::Transform(const std::vector<Vector4>& source, i32 sourceIdx, const Quaternion& q, std::vector<Vector4>& dest, i32 destIdx, i32 count)
	{
		for (i32 i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = Transform(source[i], q);
		}
	}

	void Vector4::Transform(const std::vector<Vector4>& source, const Matrix& mat, std::vector<Vector4>& dest)
	{
		Transform(source, 0, mat, dest, 0, source.size());
	}

	void Vector4::Transform(const std::vector<Vector4>& source, const Quaternion& q, std::vector<Vector4>& dest)
	{
		Transform(source, 0, q, dest, 0, source.size());
	}

	Vector4 Vector4::TransformNormal(const Vector4& norm, const Matrix& mat)
	{
		float x = norm.X*mat.M11 + norm.Y*mat.M21 + norm.Z*mat.M31;
		float y = norm.X*mat.M12 + norm.Y*mat.M22 + norm.Z*mat.M32;
		float z = norm.X*mat.M13 + norm.Y*mat.M23 + norm.Z*mat.M33;
		float w = norm.X*mat.M14 + norm.Y*mat.M24 + norm.Z*mat.M34;
															 
		return Vector4(x, y, z, 0);
	}

	void Vector4::TransformNormal(const std::vector<Vector4>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector4>& dest, i32 destIdx, i32 count)
	{
		for (i32 i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = TransformNormal(source[i], mat);
		}
	}

	void Vector4::TransformNormal(const std::vector<Vector4>& source, const Matrix& mat, std::vector<Vector4>& dest)
	{
		TransformNormal(source, 0, mat, dest, 0, source.size());
	}

	Vector4& Vector4::operator+=(const Vector4& v)
	{
		X += v.X; 
		Y += v.Y;
		Z += v.Z;
		W += v.W;
		return *this;
	}

	Vector4& Vector4::operator-=(const Vector4& v)
	{
		X /= v.X;
		Y /= v.Y;
		Z /= v.Z;
		W /= v.W;
		return *this;
	}

	Vector4& Vector4::operator*=(const Vector4& v)
	{
		X *= v.X;
		Y *= v.Y;
		Z *= v.Z;
		W *= v.W;
		return *this;
	}

	Vector4& Vector4::operator*=(float f)
	{
		X *= f;
		Y *= f;
		Z *= f;
		W *= f;
		return *this;
	}

	Vector4& Vector4::operator/=(const Vector4& v)
	{
		X /= v.X;
		Y /= v.Y;
		Z /= v.Z;
		W /= v.W;
		return *this;
	}

	Vector4& Vector4::operator/=(float f)
	{
		X /= f;
		Y /= f;
		Z /= f;
		W /= f;
		return *this;
	}

	Vector4 operator+(Vector4 lhs, const Vector4& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	Vector4 operator-(Vector4 lhs, const Vector4& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	Vector4 operator*(Vector4 lhs, const Vector4& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	Vector4 operator*(float lhs, Vector4 rhs)
	{
		rhs *= lhs;
		return rhs;
	}

	Vector4 operator*(Vector4 lhs, float rhs)
	{
		return rhs*lhs;
	}

	Vector4 operator/(Vector4 lhs, const Vector4& rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	Vector4 operator/(Vector4 lhs, float rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	Vector4 operator-(Vector4 rhs)
	{
		rhs.X = -rhs.X;
		rhs.Y = -rhs.Y;
		rhs.Z = -rhs.Z;
		rhs.W = -rhs.W;
		return rhs;
	}

	bool operator==(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.X == rhs.X
			&& lhs.Y == rhs.Y
			&& lhs.Z == rhs.Z
			&& lhs.W == rhs.W;
	}

	bool operator!=(const Vector4& lhs, const Vector4& rhs)
	{
		return !(lhs == rhs);
	}
}
