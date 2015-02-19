#ifndef _MATRIX_H
#define _MATRIX_H

#include <memory>

namespace YAX
{
	struct Vector3;
	struct Quaternion;
	struct Plane;

	struct Matrix
	{

		float M11, M12, M13, M14,
			  M21, M22, M23, M24,
			  M31, M32, M33, M34,
			  M41, M42, M43, M44;
		
		static const Matrix Identity;
		static const Matrix CatmullRomMat;

		Matrix(
			float, float, float, float,
			float, float, float, float,
			float, float, float, float,
			float, float, float, float
		);

		Vector3 Backward() const;
		void Backward(const Vector3&);

		Vector3 Down() const;
		void Down(const Vector3&);

		Vector3 Forward() const;
		void Forward(const Vector3&);

		Vector3 Left() const;
		void Left(const Vector3&);

		Vector3 Right() const;
		void Right(const Vector3&);

		Vector3 Translation() const;
		void Translation(const Vector3&);

		Vector3 Up() const;
		void Up(const Vector3&);

		bool Decompose(Vector3& scale, Quaternion& rot, Vector3& trans) const;
		float Determinant() const;

		static Matrix CreateBillboard(const Vector3& objectPos, const Vector3& cameraPos, const Vector3& cameraUp, const Vector3* cameraForward);
		static Matrix CreateConstrainedBillboard(const Vector3& objectPos, const Vector3& cameraPos, const Vector3& rotAxis, const Vector3* cameraForward, const Vector3* objectForward);
		static Matrix CreateFromAxisAngle(const Vector3& axis, float angle);
		static Matrix CreateFromQuaternion(const Quaternion& q);
		static Matrix CreateFromYawPitchRoll(float y, float p, float r);
		static Matrix CreateLookAt(const Vector3& cameraPos, const Vector3& cameraTarg, const Vector3& cameraUp);
		static Matrix CreateOrthographic(float width, float height, float zNear, float zFar);
		static Matrix CreateOrthographicOffCenter(float left, float right, float bottom, float top, float zNear, float zFar);
		static Matrix CreatePerspective(float width, float height, float zNear, float zFar);
		static Matrix CreatePerspectiveFieldOfView(float fieldOfView, float aspectRatio, float zNear, float zFar);
		static Matrix CreatePerspectiveOffCenter(float left, float right, float bottom, float top, float zNear, float zFar);
		static Matrix CreateReflection(const Plane& val);
		static Matrix CreateRotationX(float angle);
		static Matrix CreateRotationY(float angle);
		static Matrix CreateRotationZ(float angle); 
		static Matrix CreateScale(float scale);
		static Matrix CreateScale(float scaleX, float scaleY, float scaleZ);
		static Matrix CreateScale(const Vector3& scaleVec);
		static Matrix CreateShadow(const Vector3& lightDir, const Plane& plane);
		static Matrix CreateTranslation(float xT, float yT, float zT);
		static Matrix CreateTranslation(const Vector3& vec);
		static Matrix CreateWorld(Vector3 pos, Vector3 fwd, Vector3 up);

		static Matrix Invert(const Matrix& mat);
		static Matrix Lerp(const Matrix& from, const Matrix& to, float t);
		static Matrix Transform(const Matrix& mat, const Quaternion& rotation);
		static Matrix Transpose(const Matrix& mat);

		Matrix& operator+=(const Matrix&);
		Matrix& operator-=(const Matrix&);
		Matrix& operator*=(const Matrix&);
		Matrix& operator*=(float);
		Matrix& operator/=(const Matrix&);
		Matrix& operator/=(float);
	};

	Matrix operator+(Matrix, const Matrix&);
	Matrix operator-(Matrix, const Matrix&);
	Matrix operator*(Matrix, const Matrix&);
	Matrix operator*(float, const Matrix&);
	Matrix operator*(Matrix, float);
	Matrix operator/(Matrix, const Matrix&);
	Matrix operator/(Matrix, float);
	Matrix operator-(const Matrix&);

	bool operator==(const Matrix&, const Matrix&);
	bool operator!=(const Matrix&, const Matrix&);
}


#endif