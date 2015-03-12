#include "../include/Quaternion.h"

#include "../include/MathHelper.h" 
#include "../include/Matrix.h"
#include "../include/Vector3.h"

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

	Quaternion Quaternion::Concatenate(const Quaternion& f, const Quaternion& s)
	{
		return s*f;
	}

	Quaternion Quaternion::Conjugate(Quaternion q)
	{
		q.Conjugate();
		return q;
	}

	Quaternion Quaternion::CreateFromAxisAngle(const Vector3& axis, float angle)
	{
		float s = std::sin(angle / 2);
		return Quaternion(axis*s, std::cos(angle / 2));
	}

	Quaternion Quaternion::CreateFromRotationMatrix(const Matrix& m)
	{
		float w = 0.5f*std::sqrt(1 + m.M11 - m.M22 - m.M33);
		float inv = 1 / (4 * w);
		return Quaternion(inv*(m.M23 - m.M32),
						  inv*(m.M31 - m.M13),
						  inv*(m.M12 - m.M21),
						  w);
	}

	Quaternion Quaternion::CreateFromYawPitchRoll(float y, float p, float r)
	{
		Quaternion pitch = Quaternion::CreateFromAxisAngle(Vector3::Right, p);
		Quaternion yaw = Quaternion::CreateFromAxisAngle(Vector3::Up, y);
		Quaternion roll = Quaternion::CreateFromAxisAngle(Vector3::Backward, r);

		return yaw*pitch*roll;
	}

	float Quaternion::Dot(const Quaternion& q1, const Quaternion& q2)
	{
		return q1.X*q2.X + q1.Y*q2.Y + q1.Z*q2.Z + q1.W*q2.W;
	}

	Quaternion Quaternion::Inverse(Quaternion q)
	{
		q.Conjugate();
		q /= q.LengthSquared();
		return q;
	}

	Quaternion Quaternion::Lerp(const Quaternion& from, const Quaternion& to, float t)
	{
		return Quaternion(MathHelper::Lerp(from.X, to.X, t),
						  MathHelper::Lerp(from.Y, to.Y, t),
						  MathHelper::Lerp(from.Z, to.Z, t),
						  MathHelper::Lerp(from.W, to.W, t));
	}

	Quaternion Quaternion::Normalize(Quaternion q)
	{
		q /= q.Length();
		return q;
	}

#pragma region SLERP Operations
	Quaternion QLn(Quaternion q)
	{
		float len = q.Length();
		float theta = q.W / len;
		Vector3 v(q.X, q.Y, q.Z);

		return Quaternion(v * std::acosf(theta), std::logf(len));
	}

	Quaternion QExp(Quaternion q)
	{
		Vector3 v(q.X, q.Y, q.Z);
		float len = v.Length();

		return Quaternion(v / len * std::sinf(len), std::cosf(len)) * std::expf(q.W);
	}

	Quaternion QPow(Quaternion q, float p)
	{
		return QExp(QLn(q) * p);
	}
#pragma endregion

	Quaternion Quaternion::Slerp(const Quaternion& from, const Quaternion& to, float t)
	{
		float d = Quaternion::Dot(from, to);

		//If the quaternions are very close, use cheaper Lerp
		if (d < 0.999f)
			return Quaternion::Lerp(from, to, t);

		return QPow(to*Quaternion::Inverse(from), t) * from;
	}

	Quaternion& Quaternion::operator+=(const Quaternion& q)
	{
		this->X += q.X;
		this->Y += q.Y;
		this->Z += q.Z; 
		this->W += q.W;
		return *this;
	}

	Quaternion& Quaternion::operator-=(const Quaternion& q)
	{
		this->X -= q.X;
		this->Y -= q.Y;
		this->Z -= q.Z;
		this->W -= q.W;
		return *this;
	}

	Quaternion& Quaternion::operator*=(const Quaternion& q)
	{
		float x = W*q.X + X*q.W + Y*q.Z - Z*q.Y;
		float y = W*q.Y - X*q.Z + Y*q.W + Z*q.X;
		float z = W*q.Z + X*q.Y - Y*q.X + Z*q.W;
		float w = W*q.W - X*q.X - Y*q.Y - Z*q.Z;
		
		X = x;
		Y = y;
		Z = z;
		W = w;
		
		return *this;
	}

	Quaternion& Quaternion::operator*=(float f)
	{
		this->X *= f;
		this->Y *= f;
		this->Z *= f;
		this->W *= f;
		return *this;
	}

	Quaternion& Quaternion::operator/=(const Quaternion& q)
	{
		float len = q.LengthSquared();

		float x = q.W*X - q.X*W - q.Y*Z + q.Z*Y;
		float y = q.W*Y + q.X*Z - q.Y*W - q.Z*X;
		float z = q.W*Z - q.X*Y + q.Y*X - q.Z*W;
		float w = W*q.W + X*q.X + Y*q.Y + Z*q.Z;

		X = x / len;
		Y = y / len;
		Z = z / len;
		W = w / len;

		return *this;
	}

	Quaternion& Quaternion::operator/=(float f)
	{
		this->X /= f;
		this->Y /= f;
		this->Z /= f;
		this->W /= f;
		return *this;
	}

	Quaternion operator+(Quaternion lhs, const Quaternion& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	Quaternion operator-(Quaternion lhs, const Quaternion& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	Quaternion operator*(Quaternion lhs, const Quaternion& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	Quaternion operator*(Quaternion lhs, float rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	Quaternion operator*(float lhs, const Quaternion& rhs)
	{
		return rhs*lhs;
	}

	Quaternion operator/(Quaternion lhs, const Quaternion& rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	Quaternion operator/(Quaternion lhs, float rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	Quaternion operator-(Quaternion rhs)
	{
		rhs.Conjugate();
		rhs.W = -rhs.W;
		return rhs;
	}

	bool operator==(const Quaternion& lhs, const Quaternion& rhs)
	{
		return lhs.X == rhs.X 
			&& lhs.Y == rhs.Y
			&& lhs.Z == rhs.Z
			&& lhs.W == rhs.W;
	}

	bool operator!=(const Quaternion& lhs, const Quaternion& rhs)
	{
		return !(lhs == rhs);
	}
}
