#ifndef _QUATERNION_H
#define _QUATERNION_H

namespace YAX
{
	struct Vector3;
	struct Matrix;

	struct Quaternion
	{	

		float X, Y, Z, W;
		static const Quaternion Identity;

		Quaternion(float x, float y, float z, float w);
		Quaternion(Vector3 xyz, float w);

		void Conjugate();
		float Dot(const Quaternion& q) const;
		float Length() const;
		float LengthSquared() const;
		void Normalize();
		
		static Quaternion Concatenate(const Quaternion& first, const Quaternion& second);
		static Quaternion Conjugate(Quaternion);
		static Quaternion CreateFromAxisAngle(const Vector3& axis, float angle);
		static Quaternion CreateFromRotationMatrix(const Matrix& mat);
		static Quaternion CreateFromYawPitchRoll(float yaw, float pitch, float roll);
		static float Dot(const Quaternion& q1, const Quaternion& q2);
		static Quaternion Inverse(Quaternion q);
		static Quaternion Lerp(const Quaternion& from, const Quaternion& to, float t);
		static Quaternion Normalize(Quaternion q);
		static Quaternion Slerp(const Quaternion& from, const Quaternion& to, float t);

		Quaternion& operator+=(const Quaternion&);
		Quaternion& operator-=(const Quaternion&);
		Quaternion& operator*=(const Quaternion&);
		Quaternion& operator*=(float);
		Quaternion& operator/=(const Quaternion&);
		Quaternion& operator/=(float);

	};

	Quaternion operator+(Quaternion, const Quaternion&);
	Quaternion operator-(Quaternion, const Quaternion&);
	Quaternion operator*(Quaternion, const Quaternion&);
	Quaternion operator*(Quaternion, float);
	Quaternion operator*(float, const Quaternion&);
	Quaternion operator/(Quaternion, const Quaternion&);
	Quaternion operator/(Quaternion, float);
	Quaternion operator-(Quaternion);

	bool operator==(const Quaternion&, const Quaternion&);
	bool operator!=(const Quaternion&, const Quaternion&);
}


#endif