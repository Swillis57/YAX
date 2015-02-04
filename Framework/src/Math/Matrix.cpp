#include "../../include/Math/Matrix.h"
#include <exception>
#include "../../include/Geometry/Plane.h"
#include "../../include/Math/MathHelper.h"
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

	Matrix Matrix::CreateBillboard(const Vector3& objectPos, const Vector3& cameraPos,
		const Vector3& cameraUp, const Vector3* cameraForward)
	{
		float minDist = 0.0001f * 0.0001f;
		Vector3 xBasis, yBasis, zBasis;

		Vector3 camToObj = objectPos - cameraPos;

		zBasis = camToObj;
		if (camToObj.LengthSquared() < minDist)
		{
			zBasis = (cameraForward != nullptr ? -(*cameraForward) : Vector3::Normalize(camToObj));
		}

		yBasis = Vector3::Normalize(cameraUp);
		xBasis = Vector3::Normalize(Vector3::Cross(yBasis, zBasis));
		zBasis.Normalize();

		return Matrix(xBasis.X, xBasis.Y, xBasis.Z, 0,
				      yBasis.X, yBasis.Y, yBasis.Z, 0,
				      zBasis.X, zBasis.Y, zBasis.Z, 0,
				   objectPos.X, objectPos.Y, objectPos.Z, 1.0f
			);
	}

	Matrix Matrix::CreateConstrainedBillboard(const Vector3& objectPos, const Vector3& cameraPos,
		const Vector3& rotAxis, const Vector3* cameraForward, const Vector3* objectForward)
	{
		float minDist = 0.0001f * 0.0001f;

		Vector3 camToObj = objectPos - cameraPos;
		Vector3 xBasis, yBasis, zBasis;

		if (camToObj.LengthSquared() < minDist)
		{
			if (cameraForward != nullptr)
				camToObj = -(*cameraForward);
			else
				camToObj = Vector3::Forward;
		}

		yBasis = Vector3::Normalize(rotAxis);
		zBasis = camToObj;
		float rotAxisDotZ = std::abs(Vector3::Dot(rotAxis, zBasis));

		if (rotAxisDotZ > 0.998f)
		{
			if (objectForward != nullptr)
			{
				zBasis = *objectForward;
				rotAxisDotZ = std::abs(Vector3::Dot(rotAxis, zBasis));
			}
		}

		if (rotAxisDotZ > 0.998f)
		{
			zBasis = std::abs(Vector3::Dot(rotAxis, Vector3::Forward)) > 0.998f ? Vector3::Right : Vector3::Forward;
		}

		xBasis = Vector3::Normalize(Vector3::Cross(yBasis, zBasis));
		zBasis = Vector3::Normalize(Vector3::Cross(xBasis, yBasis));

		return Matrix(  xBasis.X,    xBasis.Y,    xBasis.Z, 0,
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
		//variables for sanity
		float x = q.X, y = q.Y, z = q.Z, w = q.W;

		return Matrix(1-2*y*y-2*z*z,   2*x*y-2*z*w,   2*x*z+2*y*w,   0,
					    2*x*y+2*z*w, 1-2*x*x-2*z*z,   2*y*z-2*x*w,   0,
					    2*x*z-2*y*w,   2*y*z+2*x*w, 1-2*x*x-2*y*y,   0,
								  0,			 0,		        0, 1.0f);
	}

	Matrix Matrix::CreateFromYawPitchRoll(float y, float p, float r)
	{
		return Matrix::CreateFromQuaternion(Quaternion::CreateFromYawPitchRoll(y, p, r));
	}

	Matrix Matrix::CreateLookAt(const Vector3& cameraPos, const Vector3& cameraTarg, const Vector3& cameraUp)
	{
		Vector3 zBasis = Vector3::Normalize(cameraPos - cameraTarg);
		Vector3 xBasis = Vector3::Normalize(Vector3::Cross(cameraUp, zBasis));
		Vector3 yBasis = Vector3::Normalize(Vector3::Cross(zBasis, xBasis));

		float tX = -Vector3::Dot(cameraPos, xBasis);
		float tY = -Vector3::Dot(cameraPos, yBasis);
		float tZ = -Vector3::Dot(cameraPos, zBasis);

		return Matrix(xBasis.X, xBasis.Y, xBasis.Z, 0,
					  yBasis.X, yBasis.Y, yBasis.Z, 0,
					  zBasis.X, zBasis.Y, zBasis.Z, 0,
							tX,		  tY,		tZ, 1.0f);
	}

	Matrix Matrix::CreateOrthographic(float w, float h, float zN, float zF)
	{
		return Matrix(2.0f/w,	   0,            0, 0,
						   0, 2.0f/h,            0, 0,
						   0,      0, 1.0f/(zN-zF), 0,
						   0,      0,   zN/(zN-zF), 1.0f);
	}

	Matrix Matrix::CreateOrthographicOffCenter(float l, float r, float b, float t, float zN, float zF)
	{
		return Matrix( 2.0f/(r-l),			 0,            0, 0,
								0,  2.0f/(t-b),            0, 0,
								0,			 0, 1.0f/(zN-zF), 0,
					  (l+r)/(l-r), (t+b)/(b-t),	  zN/(zN-zF), 1.0f);
	}

}