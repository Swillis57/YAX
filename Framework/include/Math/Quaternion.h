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

		Quaternion(float, float, float, float);
		Quaternion(Vector3, float);

		void Conjugate();
		float Dot(const Quaternion&) const;
		float Length() const;
		float LengthSquared() const;
		void Normalize();
		
		static Quaternion Concatenate(const Quaternion&, const Quaternion&);
		static Quaternion Conjugate(const Quaternion&);
		static Quaternion CreateFromAxisAngle(Vector3, float);
		static Quaternion CreateFromRotationMatrix(const Matrix&);
		static Quaternion CreateFromYawPitchRoll(float, float, float);
		static float Dot(const Quaternion&, const Quaternion&);
		static Quaternion Inverse(const Quaternion&);
		static Quaternion Lerp(const Quaternion&, const Quaternion&, float);
		static Quaternion Normalize(const Quaternion&);
		static Quaternion Slerp(const Quaternion&, const Quaternion&, float);


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