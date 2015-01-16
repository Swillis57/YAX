#ifndef _VEC3_H
#define _VEC3_H

#include <vector>
#include "../Utils.h"


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

		Vector3(float);
		Vector3(float, float, float);
		Vector3(Vector2, float);


		static Vector3 Barycentric(const Vector3&, const Vector3&, const Vector3&, float, float);
		static Vector3 CatmullRom(const Vector3&, const Vector3&, const Vector3&, float);
		static Vector3 Clamp(const Vector3&, const Vector3&, const Vector3&);
		static Vector3 Distance(const Vector3&, const Vector3&);
		static Vector3 DistanceSquared(const Vector3&, const Vector3&);
		static Vector3 Dot(const Vector3&, const Vector3&);
		static Vector3 Hermite(const Vector3&, const Vector3&, const Vector3&, const Vector3&, float);
		static Vector3 Max(const Vector3&, const Vector3&);
		static Vector3 Min(const Vector3&, const Vector3&);
		static Vector3 Reflect(const Vector3&, const Vector3&);
		static Vector3 SmoothStep(const Vector3&, const Vector3&, float);

		static Vector3 Transform(const Vector3&, const Matrix&);
		static Vector3 Transform(const Vector3&, const Quaternion&);
		static void Transform(const std::vector<Vector3>&, i32, const Matrix&, std::vector<Vector3>&, i32, i32);
		static void Transform(const std::vector<Vector3>&, i32, const Quaternion&, std::vector<Vector3>&, i32, i32);
		static void Transform(const std::vector<Vector3>&, const Matrix&, std::vector<Vector3>&);
		static void Transform(const std::vector<Vector3>&, const Quaternion&, std::vector<Vector3>&);

		static Vector3 TransformNormal(const Vector3&, const Matrix&);
		static void TransformNormal(const std::vector<Vector3>&, i32, const Matrix&, std::vector<Vector3>&, i32, i32);
		static void TransformNormal(const std::vector<Vector3>&, const Matrix&, std::vector<Vector3>&);

		Vector3 Normalize();
		float Length();
		float LengthSquared();

		Vector3 operator+(const Vector3&);
		Vector3 operator-(const Vector3&);
		Vector3 operator*(const Vector3&);
		Vector3 operator*(float);
		Vector3 operator/(const Vector3&);
		Vector3 operator/(float);
		Vector3 operator-();

		bool operator==(const Vector3&);
		bool operator!=(const Vector3&);


	};
}


#endif