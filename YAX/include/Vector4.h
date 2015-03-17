#ifndef _VEC4_H
#define _VEC4_H

#include <vector>
#include "../../YAX/include/Utils.h"

namespace YAX
{
	struct Vector2;
	struct Vector3;
	struct Matrix;
	struct Quaternion;

	struct Vector4
	{
		static const Vector4 One, UnitX, UnitY, UnitZ, UnitW, Zero;
		
		float X, Y, Z, W;
		
		Vector4();
		Vector4(float val);
		Vector4(float x, float y, float z, float w);
		Vector4(Vector2 xy, float z, float w);
		Vector4(Vector3 xyz, float w);

		void Normalize();
		float Length();
		float LengthSquared();

		static Vector4 Barycentric(const Vector4& p1, const Vector4& p2, const Vector4& p3, float b2, float b3);
		static Vector4 CatmullRom(const Vector4& p1, const Vector4& p2, const Vector4& p3, const Vector4& p4, float amt);
		static Vector4 Clamp(const Vector4& val, const Vector4& min, const Vector4& max);
		static float Distance(const Vector4& p1, const Vector4& p2);
		static float DistanceSquared(const Vector4& p1, const Vector4& p2);
		static float Dot(const Vector4& v1, const Vector4& v2);
		static Vector4 Hermite(const Vector4& p1, const Vector4& t1, const Vector4& p2, const Vector4& t2, float amt);
		static Vector4 Lerp(const Vector4& from, const Vector4& to, float t);
		static Vector4 Max(const Vector4& v1, const Vector4& v2);
		static Vector4 Min(const Vector4& v1, const Vector4& v2);
		static Vector4 Normalize(Vector4 v);
		static Vector4 SmoothStep(const Vector4& from, const Vector4& to, float t);

		static Vector4 Transform(const Vector4& vec, const Matrix& mat);
		static Vector4 Transform(const Vector4& vec, const Quaternion& q);
		static void Transform(const std::vector<Vector4>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector4>& dest, i32 destIdx, i32 count);
		static void Transform(const std::vector<Vector4>& source, i32 sourceIdx, const Quaternion& q, std::vector<Vector4>& dest, i32 destIdx, i32 count);
		static void Transform(const std::vector<Vector4>& source, const Matrix& mat, std::vector<Vector4>& dest);
		static void Transform(const std::vector<Vector4>& source, const Quaternion& q, std::vector<Vector4>& dest);

		static Vector4 TransformNormal(const Vector4& norm, const Matrix& mat);
		static void TransformNormal(const std::vector<Vector4>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector4>& dest, i32 destIdx, i32 count);
		static void TransformNormal(const std::vector<Vector4>& source, const Matrix& mat, std::vector<Vector4>& dest);

		Vector4& operator+=(const Vector4&);
		Vector4& operator-=(const Vector4&);
		Vector4& operator*=(const Vector4&);
		Vector4& operator*=(float);
		Vector4& operator/=(const Vector4&);
		Vector4& operator/=(float);

	};

	Vector4 operator+(Vector4, const Vector4&);
	Vector4 operator-(Vector4, const Vector4&);
	Vector4 operator*(Vector4, const Vector4&);
	Vector4 operator*(float, Vector4);
	Vector4 operator*(Vector4, float);
	Vector4 operator/(Vector4, const Vector4&);
	Vector4 operator/(Vector4, float);
	Vector4 operator-(Vector4);

	bool operator==(const Vector4&, const Vector4&);
	bool operator!=(const Vector4&, const Vector4&);
}


#endif