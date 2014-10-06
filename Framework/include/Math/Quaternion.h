#ifndef _QUATERNION_H
#define _QUATERNION_H

#include "Vector3.h"
#include "Matrix.h"

namespace XNA
{
	struct Vector3;
	struct Matrix;

	struct Quaternion
	{	

		float X, Y, Z, W;
		static const Quaternion Identity;

		Quaternion(float, float, float, float);
		Quaternion(Vector3, float);

		static Quaternion Concatenate(const Quaternion&, const Quaternion&);
		void Conjugate();
		Quaternion Conjugate(const Quaternion&);
		static Quaternion CreateFromAxisAngle(Vector3, float);
		static Quaternion CreateFromRotationMatrix(const Matrix&);
		static Quaternion CreateFromYawPitchRoll(float, float, float);
		float Dot(const Quaternion&);
		static float Dot(const Quaternion&, const Quaternion&);
		Quaternion Inverse();
		static Quaternion Inverse(const Quaternion&);
		float Length();
		float LengthSquared();
		Quaternion Lerp(const Quaternion&, const Quaternion&, float);
		void Normalize();
		static Quaternion Normalize(const Quaternion&);
		Quaternion Slerp(const Quaternion&, const Quaternion&, float);

		Quaternion& operator=(const Quaternion&) const;
		Quaternion operator+(const Quaternion&) const;
		Quaternion operator-(const Quaternion&) const;
		Quaternion operator*(const Quaternion&) const;
		Quaternion operator*(float);
		Quaternion operator/(const Quaternion&) const;
		Quaternion operator/(float);
		Quaternion operator-() const;
		bool operator==(const Quaternion&) const;
		bool operator!=(const Quaternion&) const;


	};
}


#endif