#ifndef _VEC4_H
#define _VEC4_H

#include <vector>
#include "../Utils.h"

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
		
		

		Vector4(float);
		Vector4(float, float, float, float);
		Vector4(Vector2, float, float);
		Vector4(Vector3, float);


		static Vector4 Barycentric(const Vector4&, const Vector4&, const Vector4&, float, float);
		static Vector4 CatmullRom(const Vector4&, const Vector4&, const Vector4&, float);
		static Vector4 Clamp(const Vector4&, const Vector4&, const Vector4&);
		static Vector4 Distance(const Vector4&, const Vector4&);
		static Vector4 DistanceSquared(const Vector4&, const Vector4&);
		static Vector4 Dot(const Vector4&, const Vector4&);
		static Vector4 Hermite(const Vector4&, const Vector4&, const Vector4&, const Vector4&, float);
		static Vector4 Max(const Vector4&, const Vector4&);
		static Vector4 Min(const Vector4&, const Vector4&);
		static Vector4 Reflect(const Vector4&, const Vector4&);
		static Vector4 SmoothStep(const Vector4&, const Vector4&, float);

		static Vector4 Transform(const Vector4&, const Matrix&);
		static Vector4 Transform(const Vector4&, const Quaternion&);
		static void Transform(const std::vector<Vector4>&, i32, const Matrix&, std::vector<Vector4>&, i32, i32);
		static void Transform(const std::vector<Vector4>&, i32, const Quaternion&, std::vector<Vector4>&, i32, i32);
		static void Transform(const std::vector<Vector4>&, const Matrix&, std::vector<Vector4>&);
		static void Transform(const std::vector<Vector4>&, const Quaternion&, std::vector<Vector4>&);

		static Vector4 TransformNormal(const Vector4&, const Matrix&);
		static void TransformNormal(const std::vector<Vector4>&, i32, const Matrix&, std::vector<Vector4>&, i32, i32);
		static void TransformNormal(const std::vector<Vector4>&, const Matrix&, std::vector<Vector4>&);

		Vector4 Normalize();
		float Length();
		float LengthSquared();

		Vector4 operator+(const Vector4&);
		Vector4 operator-(const Vector4&);
		Vector4 operator*(const Vector4&);
		Vector4 operator*(float);
		Vector4 operator/(const Vector4&);
		Vector4 operator/(float);
		Vector4 operator-();

		bool operator==(const Vector4&);
		bool operator!=(const Vector4&);

	};
}


#endif