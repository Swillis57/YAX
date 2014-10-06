#ifndef _VEC2_H
#define _VEC2_H

#include <vector>
#include "../Utils.h"


namespace XNA
{
	struct Matrix;
	struct Quaternion;

	struct Vector2
	{
	
		float X, Y;
		static const Vector2 One, UnitX, UnitY, Zero;

		Vector2(float);
		Vector2(float x, float y) { X = x; Y = y; }

		
		static Vector2 Barycentric(const Vector2&, const Vector2&, const Vector2&, float, float);
		static Vector2 CatmullRom(const Vector2&, const Vector2&, const Vector2&, float);
		static Vector2 Clamp(const Vector2&, const Vector2&, const Vector2&);
		static Vector2 Distance(const Vector2&, const Vector2&);
		static Vector2 DistanceSquared(const Vector2&, const Vector2&);
		static Vector2 Dot(const Vector2&, const Vector2&);
		static Vector2 Hermite(const Vector2&, const Vector2&, const Vector2&, const Vector2&, float);
		static Vector2 Max(const Vector2&, const Vector2&);
		static Vector2 Min(const Vector2&, const Vector2&);
		static Vector2 Reflect(const Vector2&, const Vector2&);
		static Vector2 SmoothStep(const Vector2&, const Vector2&, float);

		static Vector2 Transform(const Vector2&, const Matrix&);
		static Vector2 Transform(const Vector2&, const Quaternion&);
		static void Transform(const std::vector<Vector2>&, i32, const Matrix&, std::vector<Vector2>&, i32, i32);
		static void Transform(const std::vector<Vector2>&, i32, const Quaternion&, std::vector<Vector2>&, i32, i32);
		static void Transform(const std::vector<Vector2>&, const Matrix&, std::vector<Vector2>&);
		static void Transform(const std::vector<Vector2>&, const Quaternion&, std::vector<Vector2>&);

		static Vector2 TransformNormal(const Vector2&, const Matrix&);
		static void TransformNormal(const std::vector<Vector2>&, i32, const Matrix&, std::vector<Vector2>&, i32, i32);
		static void TransformNormal(const std::vector<Vector2>&, const Matrix&, std::vector<Vector2>&);
		
		Vector2 Normalize();
		float Length();
		float LengthSquared();

		Vector2 operator+(const Vector2&);
		Vector2 operator-(const Vector2&);
		Vector2 operator*(const Vector2&);
		Vector2 operator*(float);
		Vector2 operator/(const Vector2&);
		Vector2 operator/(float);
		Vector2 operator-();

		bool operator==(const Vector2&);
		bool operator!=(const Vector2&);
		
	
		
	};
}


#endif