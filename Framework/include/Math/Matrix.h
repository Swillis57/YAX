#ifndef _MATRIX_H
#define _MATRIX_H

#include <tuple>
#include <memory>

namespace XNA
{
	class Vector3;
	class Quaternion;
	class Plane;

	struct Matrix
	{

		float M11, M12, M13, M14,
			  M21, M22, M23, M24,
			  M31, M32, M33, M34,
			  M41, M42, M43, M44;
		
		static const Matrix Identity;

		Matrix(
			float, float, float, float,
			float, float, float, float,
			float, float, float, float,
			float, float, float, float
			);

		Vector3 Backward();
		void Backward(const Vector3&);

		Vector3 Down();
		void Down(const Vector3&);

		Vector3 Forward();
		void Forward(const Vector3&);

		Vector3 Left();
		void Left(const Vector3&);

		Vector3 Right();
		void Right(const Vector3&);

		Vector3 Translation();
		void Translation(const Vector3&);

		Vector3 Up();
		void Up(const Vector3&);


		static Matrix CreateBillboard(const Vector3&, const Vector3&, const Vector3&, std::unique_ptr<Vector3>);
		static Matrix CreateConstrainedBillboard(const Vector3&, const Vector3&, const Vector3&, std::unique_ptr<Vector3>, std::unique_ptr<Vector3>);
		static Matrix CreateFromAxisAngle(const Vector3&, float);
		static Matrix CreateFromQuaternion(const Quaternion&);
		static Matrix CreateFromYawPitchRoll(float, float, float);
		static Matrix CreateLookAt(const Vector3&, const Vector3&, const Vector3&);
		static Matrix CreateOrthographic(float, float, float, float);
		static Matrix CreateOrthographicOffCenter(float, float, float, float, float, float);
		static Matrix CreatePerspective(float, float, float, float);
		static Matrix CreatePerspectiveFieldOfView(float, float, float, float);
		static Matrix CreatePerspectiveOffCenter(float, float, float, float, float, float);
		static Matrix CreateReflection(const Plane&);
		static Matrix CreateRotationX(float);
		static Matrix CreateRotationY(float);
		static Matrix CreateRotationZ(float);

		static Matrix CreateScale(float);
		static Matrix CreateScale(float, float, float);
		static Matrix CreateScale(const Vector3&);
		static Matrix CreateShadow(const Vector3&, const Plane&);
		static Matrix CreateTranslation(float, float, float, float);
		static Matrix CreateTranslation(const Vector3&);
		static Matrix CreateWorld(const Vector3&, const Vector3&, const Vector3&);

		bool Decompose(Vector3*, Quaternion*, Vector3*);
		float Determinant();

		static Matrix Invert(const Matrix&);
		static Matrix Lerp(const Matrix&, const Matrix&, float);
		static Matrix Transform(const Matrix&, const Quaternion&);
		static Matrix Transpose(const Matrix&);

		Matrix operator+(const Matrix&);
		Matrix operator-(const Matrix&);
		Matrix operator*(const Matrix&);
		Matrix operator*(float);
		Matrix operator/(const Matrix&);
		Matrix operator/(float);
		Matrix operator-();

		bool operator==(const Matrix&);
		bool operator!=(const Matrix&);
	};
}


#endif