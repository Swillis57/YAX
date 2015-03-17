#ifndef _VEC2_H
#define _VEC2_H

#include <vector>
#include "../../YAX/include/Utils.h"


namespace YAX
{
	struct Matrix;
	struct Quaternion;

	struct Vector2
	{
		static const Vector2 One, UnitX, UnitY, Zero;

		float X, Y;


		Vector2(float val);
		Vector2(float x, float y);


		void Normalize();
		float Length() const;
		float LengthSquared() const;

		static Vector2 Barycentric(const Vector2& p1, const Vector2& p2, const Vector2& p3, float b2, float b3);
		static Vector2 CatmullRom(const Vector2& p1, const Vector2& p2, const Vector2& p3, const Vector2& p4, float t);
		static Vector2 Clamp(const Vector2& point, const Vector2& min, const Vector2& max);
		static float Distance(const Vector2& p1, const Vector2& p2);
		static float DistanceSquared(const Vector2& p1, const Vector2& p2);
		static float Dot(const Vector2& v1, const Vector2& v2);
		static Vector2 Hermite(const Vector2& p1, const Vector2& t1, const Vector2& p2, const Vector2& t2, float w);
		static Vector2 Lerp(const Vector2& v1, const Vector2& v2, float t);
		static Vector2 Max(const Vector2& v1, const Vector2& v2);
		static Vector2 Min(const Vector2& v1, const Vector2& v2);
		static Vector2 Normalize(Vector2 vec);
		static Vector2 Reflect(const Vector2& vec, const Vector2& normal);
		static Vector2 SmoothStep(const Vector2& v1, const Vector2& v2, float t);

		static Vector2 Transform(const Vector2& v, const Matrix& m);
		static Vector2 Transform(const Vector2& v, const Quaternion& q);
		static void Transform(const std::vector<Vector2>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector2>& dest, i32 destIdx, i32 count);
		static void Transform(const std::vector<Vector2>& source, i32 sourceIdx, const Quaternion& q, std::vector<Vector2>& dest, i32 destIdx, i32 count);
		static void Transform(const std::vector<Vector2>& source, const Matrix& mat, std::vector<Vector2>& dest);
		static void Transform(const std::vector<Vector2>& source, const Quaternion& q, std::vector<Vector2>& dest);

		static Vector2 TransformNormal(const Vector2& normal, const Matrix& mat);
		static void TransformNormal(const std::vector<Vector2>& source, i32 sourceIdx, const Matrix& mat, std::vector<Vector2>& dest, i32 destIdx, i32 count);
		static void TransformNormal(const std::vector<Vector2>& source, const Matrix& mat, std::vector<Vector2>& dest);
	
		Vector2& operator+=(const Vector2&); 
		Vector2& operator-=(const Vector2&);
		Vector2& operator*=(const Vector2&);
		Vector2& operator*=(float);
		Vector2& operator/=(const Vector2&);
		Vector2& operator/=(float);
	};

	Vector2 operator+(const Vector2&, const Vector2&);
	Vector2 operator-(const Vector2&, const Vector2&);
	Vector2 operator*(const Vector2&, const Vector2&);
	Vector2 operator*(const Vector2&, float);
	Vector2 operator*(float, const Vector2&);
	Vector2 operator/(const Vector2&, const Vector2&);
	Vector2 operator/(const Vector2&, float);
	Vector2 operator-(const Vector2&);

	bool operator==(const Vector2&, const Vector2&);
	bool operator!=(const Vector2&, const Vector2&);
}


#endif