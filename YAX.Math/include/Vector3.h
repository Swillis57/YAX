#ifndef _VEC3_H
#define _VEC3_H

#include <vector>
#include "../../YAX/include/Utils.h"


namespace YAX
{
	struct Matrix;
	struct Quaternion;
	struct Vector2;

	struct Vector3
	{
		static const Vector3 One, UnitX, UnitY, UnitZ, Zero, 
							 Backward, Down, Forward, Left,
							 Right, Up;

		float X, Y, Z;

		Vector3();
		Vector3(float val);
		Vector3(float x, float y, float z);
		Vector3(Vector2 xy, float z);

		void Normalize();
		float Length() const;
		float LengthSquared() const;

		static Vector3 Barycentric(const Vector3& p1, const Vector3& p2, const Vector3& p3, float b2, float b3);
		static Vector3 CatmullRom(const Vector3& p1, const Vector3& p2, const Vector3& p3, const Vector3& p4, float amt);
		static Vector3 Clamp(const Vector3& val, const Vector3& min, const Vector3& max);
		static Vector3 Cross(const Vector3& v1, const Vector3 v2);
		static float Distance(const Vector3& p1, const Vector3& p2);
		static float DistanceSquared(const Vector3& p1, const Vector3& p2);
		static float Dot(const Vector3& v1, const Vector3& v2);
		static Vector3 Hermite(const Vector3& p1, const Vector3& t1, const Vector3& p2, const Vector3& t2, float w);
		static Vector3 Max(const Vector3& v1, const Vector3& v2);
		static Vector3 Min(const Vector3& v1, const Vector3& v2);
		static Vector3 Normalize(Vector3 vec);
		static Vector3 Reflect(const Vector3& vec, const Vector3& norm);
		static Vector3 SmoothStep(const Vector3& a, const Vector3& b, float t);

		static Vector3 Transform(const Vector3& vec, const Matrix& mat);
		static Vector3 Transform(const Vector3& vec, const Quaternion& q);
		static void Transform(const std::vector<Vector3>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector3>& dest, i32 destIdx, i32 count);
		static void Transform(const std::vector<Vector3>& source, i32 sourceIdx, const Quaternion& q, std::vector<Vector3>& dest, i32 destIdx, i32 count);
		static void Transform(const std::vector<Vector3>& source, const Matrix& mat, std::vector<Vector3>& dest);
		static void Transform(const std::vector<Vector3>& source, const Quaternion& q, std::vector<Vector3>& dest);

		static Vector3 TransformNormal(const Vector3& norm, const Matrix& mat);
		static void TransformNormal(const std::vector<Vector3>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector3>& dest, i32 destIdx, i32 count);
		static void TransformNormal(const std::vector<Vector3>& source, const Matrix& mat, std::vector<Vector3>& dest);

		Vector3& operator+=(const Vector3&);
		Vector3& operator-=(const Vector3&);
		Vector3& operator*=(const Vector3&);
		Vector3& operator*=(float);
		Vector3& operator/=(const Vector3&);
		Vector3& operator/=(float);
	};

	Vector3 operator+(const Vector3&, const Vector3&);
	Vector3 operator-(const Vector3&, const Vector3&);
	Vector3 operator*(const Vector3&, const Vector3&);
	Vector3 operator*(const Vector3&, float);
	Vector3 operator*(float, const Vector3&);
	Vector3 operator/(const Vector3&, const Vector3&);
	Vector3 operator/(const Vector3&, float);
	Vector3 operator-(const Vector3&);

	bool operator==(const Vector3&, const Vector3&);
	bool operator!=(const Vector3&, const Vector3&);
	bool operator>(const Vector3&, const Vector3&);
	bool operator<(const Vector3&, const Vector3&);
	bool operator>=(const Vector3&, const Vector3&);
	bool operator<=(const Vector3&, const Vector3&);
}


#endif