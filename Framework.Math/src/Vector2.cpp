#include "../include/Vector2.h"
#include <cmath>
#include "../include/Matrix.h"
#include "../include/Quaternion.h"
#include "../include/MathHelper.h"

namespace YAX
{
	const Vector2 Vector2::One = Vector2(1);
	const Vector2 Vector2::UnitX = Vector2(1, 0);
	const Vector2 Vector2::UnitY = Vector2(0, 1);
	const Vector2 Vector2::Zero = Vector2(0);

	Vector2::Vector2(float val)
		: X(val), Y(val)
	{}

	Vector2::Vector2(float x, float y)
		: X(x), Y(y)
	{}

	void Vector2::Normalize()
	{
		(*this) /= this->Length();
	}

	float Vector2::Length() const
	{
		return std::sqrt(LengthSquared());
	}

	float Vector2::LengthSquared() const
	{
		return Vector2::Dot(*this, *this);
	}

	Vector2 Vector2::Barycentric(const Vector2& p1, const Vector2& p2, const Vector2& p3, float b2, float b3)
	{
		return (1 - b2 - b3)*p1 + b2*p2 + b3*p3;
	}

	Vector2 Vector2::CatmullRom(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4, float t)
	{
		float x = MathHelper::CatmullRom(p1.X, p2.X, p3.X, p4.X, t);
		float y = MathHelper::CatmullRom(p1.Y, p2.Y, p3.Y, p4.Y, t);
		return Vector2(x, y);
	}

	Vector2 Vector2::Clamp(const Vector2& point, const Vector2& min, const Vector2& max)
	{
		float x = MathHelper::Clamp(point.X, min.X, max.X);
		float y = MathHelper::Clamp(point.Y, min.Y, max.Y);
		return Vector2(x, y);
	}

	float Vector2::Distance(const Vector2& p1, const Vector2& p2)
	{
		return (p1 - p2).Length();
	}

	float Vector2::DistanceSquared(const Vector2& p1, const Vector2& p2)
	{
		return (p1 - p2).LengthSquared();
	}

	float Vector2::Dot(const Vector2& v1, const Vector2& v2)
	{
		return v1.X * v2.X + v1.Y * v2.Y;
	}

	Vector2 Vector2::Hermite(const Vector2& p1, const Vector2& t1, const Vector2& p2, const Vector2& t2, float w)
	{
		float x = MathHelper::Hermite(p1.X, t1.X, p2.X, t2.X, w);
		float y = MathHelper::Hermite(p1.Y, t1.Y, p2.Y, t2.Y, w);
		return Vector2(x, y);
	}

	Vector2 Vector2::Lerp(const Vector2& v1, const Vector2& v2, float t)
	{
		return v1 + (v2 - v1)*t;
	}

	Vector2 Vector2::Max(const Vector2& v1, const Vector2& v2)
	{
		return Vector2(
			MathHelper::Max(v1.X, v2.X), 
			MathHelper::Max(v1.Y, v2.Y)
		);
	}

	Vector2 Vector2::Min(const Vector2& v1, const Vector2& v2)
	{
		return Vector2(
			MathHelper::Min(v1.X, v2.X),
			MathHelper::Min(v1.Y, v2.Y)
		);
	}

	Vector2 Vector2::Normalize(Vector2 vec)
	{
		vec.Normalize();
		return vec;
	}

	Vector2 Vector2::Reflect(const Vector2& vec, const Vector2& normal)
	{
		Vector2 projection = Dot(vec, normal) * normal;
		Vector2 perp = projection - vec;
		return vec + 2 * perp;
	}

	Vector2 Vector2::SmoothStep(const Vector2& v1, const Vector2& v2, float t)
	{
		float x = MathHelper::SmoothStep(v1.X, v2.X, t);
		float y = MathHelper::SmoothStep(v1.Y, v2.Y, t);
		return Vector2(x, y);
	}

	Vector2 Vector2::Transform(const Vector2& v, const Matrix& m)
	{
		//Post-multiplication - v' = v*m
		//Only calculates the first two components because
		//that's all we care about
		return Vector2(
			v.X * m.M11 + v.Y * m.M21 + m.M41,
			v.X * m.M12 + v.Y * m.M22 + m.M42
		);
	}

	Vector2 Vector2::Transform(const Vector2& v, const Quaternion& q)
	{
		Quaternion vQ(0, v.X, v.Y, 0);
		Quaternion res = q * vQ * Quaternion::Conjugate(q);
		return Vector2(res.X, res.Y);
	}

	void Vector2::Transform(const std::vector<Vector2>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector2>& dest, i32 destIdx, i32 count)
	{
		for (auto i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = Vector2::Transform(source[i], mat);
		}
	}

	void Vector2::Transform(const std::vector<Vector2>& source, i32 sourceIdx, const Quaternion& q, std::vector<Vector2>& dest, i32 destIdx, i32 count)
	{
		for (auto i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = Vector2::Transform(source[i], q);
		}
	}

	void Vector2::Transform(const std::vector<Vector2>& source, const Matrix& mat, std::vector<Vector2>& dest)
	{
		Transform(source, 0, mat, dest, 0, source.size());
	}

	void Vector2::Transform(const std::vector<Vector2>& source, const Quaternion& q, std::vector<Vector2>& dest)
	{
		Transform(source, 0, q, dest, 0, source.size());
	}

	Vector2 Vector2::TransformNormal(const Vector2& normal, const Matrix& mat)
	{
		return Vector2
		(
			normal.X * mat.M11 + normal.Y * mat.M21,
			normal.X * mat.M12 + normal.Y * mat.M22
		);
	}	

	void Vector2::TransformNormal(const std::vector<Vector2>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector2>& dest, i32 destIdx, i32 count)
	{
		for (auto i = sourceIdx; i < sourceIdx + count; i++)
		{
			dest[destIdx + (i - sourceIdx)] = Vector2::TransformNormal(source[i], mat);
		}
	}

	void Vector2::TransformNormal(const std::vector<Vector2>& source, const Matrix& mat, std::vector<Vector2>& dest)
	{
		TransformNormal(source, 0, mat, dest, 0, source.size());
	}

	Vector2& Vector2::operator+=(const Vector2& rhs)
	{
		this->X += rhs.X;
		this->Y += rhs.Y;
		return *this; 
	}

	Vector2& Vector2::operator-=(const Vector2& rhs)
	{
		this->X -= rhs.X;
		this->X -= rhs.Y;
		return *this;
	}

	Vector2& Vector2::operator*=(const Vector2& rhs)
	{
		this->X *= rhs.X;
		this->Y *= rhs.Y;
		return *this;
	}

	Vector2& Vector2::operator*=(float rhs)
	{
		this->X *= rhs;
		this->Y *= rhs;
		return *this;
	}

	Vector2& Vector2::operator/=(const Vector2& rhs)
	{
		this->X /= rhs.X;
		this->Y /= rhs.Y;
		return *this;
	}
	
	Vector2& Vector2::operator/=(float rhs)
	{
		this->X /= rhs;
		this->Y /= rhs;
		return *this;
	}

	Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.X + rhs.X, lhs.Y + rhs.Y);
	}

	Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.X - rhs.X, lhs.Y - rhs.Y);
	}

	Vector2 operator*(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.X * rhs.X, lhs.Y * rhs.Y);
	}

	Vector2 operator*(const Vector2& lhs, float rhs)
	{
		return Vector2(lhs.X * rhs, lhs.Y * rhs);
	}

	Vector2 operator*(float lhs, const Vector2& rhs)
	{
		return rhs*lhs;
	}

	Vector2 operator/(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.X / rhs.X, lhs.Y / rhs.Y);
	}

	Vector2 operator/(const Vector2& lhs, float rhs)
	{
		return Vector2(lhs.X / rhs, lhs.Y / rhs);
	}

	Vector2 operator-(const Vector2& rhs)
	{
		return Vector2(-rhs.X, -rhs.Y);
	}

	bool operator==(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.X == rhs.X &&
			   lhs.Y == rhs.Y;
	}

	bool operator!=(const Vector2& lhs, const Vector2& rhs)
	{
		return !(lhs == rhs);
	}
}