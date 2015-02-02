#include "../../include/Math/Matrix.h"
#include <cmath>
#include "../../include/Geometry/Plane.h"
#include "../../include/Math/Quaternion.h"
#include "../../include/Math/Vector3.h"

namespace YAX
{
	Matrix::Matrix(
		float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44
	) : M11(m11), M12(m12), M13(m13), M14(m14),
		M21(m21), M22(m22), M23(m23), M24(m24),
		M31(m31), M32(m32), M33(m33), M34(m34),
		M41(m41), M42(m42), M43(m43), M44(m44)
	{}

	const Matrix Matrix::Identity = Matrix(1, 0, 0, 0,
										   0, 1, 0, 0,
										   0, 0, 1, 0,
										   0, 0, 0, 1);


	Vector3 Matrix::Backward() const
	{
		return Vector3(M31, M32, M33);
	}

	void Matrix::Backward(const Vector3& source)
	{
		M31 = source.X;
		M32 = source.Y;
		M33 = source.Z;
	}

	Vector3 Matrix::Down() const
	{
		return Vector3(-M21, -M22, -M23);
	}

	void Matrix::Down(const Vector3& source)
	{
		M21 = source.X;
		M22 = source.Y;
		M23 = source.Z;
	}

	Vector3 Matrix::Forward() const
	{
		return -Backward();
	}

	void Matrix::Forward(const Vector3& source)
	{
		Backward(source);
	}

	Vector3 Matrix::Left() const
	{
		return Vector3(-M11, -M12, -M13);
	}

	void Matrix::Left(const Vector3& source)
	{
		M11 = source.X;
		M12 = source.Y; 
		M13 = source.Z;
	}

	Vector3	Matrix::Right() const
	{
		return -Left();
	}

	void Matrix::Right(const Vector3& source)
	{
		Left(source);
	}

	Vector3 Matrix::Translation() const
	{
		return Vector3(M41, M42, M43);
	}

	void Matrix::Translation(const Vector3& source)
	{
		M41 = source.X;
		M42 = source.Y;
		M43 = source.Z;
	}

	Vector3 Matrix::Up() const
	{
		return -Down();
	}

	void Matrix::Up(const Vector3& source)
	{
		Down(source);
	}

	Matrix Matrix::CreateBillboard(const Vector3& objectPos, const Vector3& cameraPos, const Vector3& cameraUp, std::unique_ptr<Vector3> cameraForward)
	{
		/*float minDist = 0.0001f;
		Vector3 camToObj = objectPos - cameraPos;

		Vector3 zBasis = camToObj.LengthSquared() > minDist*minDist ? 
					camToObj 
					: *cameraForward;
		zBasis.Normalize();
		
		Vector3 xBasis = Vector3::Cross(cameraUp, zBasis);
		xBasis.Normalize();

		return Matrix(   xBasis.X,   xBasis.Y,     xBasis.Z, 0,
					   cameraUp.X,  cameraUp.Y,  cameraUp.Z, 0,
					     zBasis.X,    zBasis.Y,    zBasis.Z, 0,
					  objectPos.X, objectPos.Y, objectPos.Z, 1.0f
					  ); 
		*/
		return CreateConstrainedBillboard(objectPos, cameraPos, cameraUp, std::move(cameraForward), nullptr);
	}

	Matrix Matrix::CreateConstrainedBillboard(const Vector3& objectPos, const Vector3& cameraPos, const Vector3& rotAxis, std::unique_ptr<Vector3> cameraForward, std::unique_ptr<Vector3> objectForward)
	{
		float minDist = 0.0001f;

		Vector3 camToObj = objectPos - cameraPos;
		Vector3 xBasis = Vector3::Cross(camToObj, rotAxis);
		Vector3 zBasis = Vector3::Zero;

		//If objectForward was provided, it acts as an override
		if (objectForward)
			zBasis = *objectForward;
		else if (camToObj.LengthSquared() > minDist*minDist)
			zBasis = *cameraForward;
		else
			zBasis = Vector3::Cross(rotAxis, xBasis);

		xBasis.Normalize();
		zBasis.Normalize();

		return Matrix(xBasis.X,    xBasis.Y,    xBasis.Z, 0,
					 rotAxis.X,   rotAxis.Y,   rotAxis.Z, 0,
				      zBasis.X,    zBasis.Y,    zBasis.Z, 0,
				   objectPos.X, objectPos.Y, objectPos.Z, 1.0f);
		
	}

	Matrix Matrix::CreateFromAxisAngle(const Vector3& axis, float angle)
	{
		float c = std::cosf(angle);
		float s = std::cosf(angle);
		float inv = 1.0f - c;

		return Matrix(       axis.X*axis.X*inv + c, axis.X*axis.Y*inv - axis.Z*s, axis.X*axis.Z*inv + axis.Y*s, 0,
					  axis.X*axis.Y*inv + axis.Z*s,        axis.Y*axis.Y*inv + c, axis.Y*axis.Z*inv - axis.X*s, 0,
					  axis.X*axis.Z*inv - axis.Y*s, axis.Y*axis.Z*inv + axis.X*s,        axis.Z*axis.Z*inv + c, 0,
												 0,							   0,							 0, 1.0f);
	}

	Matrix Matrix::CreateFromQuaternion(const Quaternion& q)
	{

	}
}