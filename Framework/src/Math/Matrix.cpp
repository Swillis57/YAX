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

	bool Matrix::Decompose(Vector3& s, Quaternion& r, Vector3& t) const
	{
		float scaleX = std::sqrt(M11*M11 + M12*M12 + M13*M13);
		float scaleY = std::sqrt(M21*M21 + M22*M22 + M23*M23);
		float scaleZ = std::sqrt(M31*M31 + M32*M32 + M33*M33);

		if (scaleX == 0 || scaleY == 0 || scaleZ == 0)
		{
			r = Quaternion::Identity;
			return false;
		}
		
		r = Quaternion::CreateFromRotationMatrix
		({
			M11/scaleX, M12/scaleX, M13/scaleX, 0,
			M21/scaleY, M22/scaleY, M23/scaleY, 0,
			M31/scaleZ, M32/scaleZ, M33/scaleZ, 0,
					 0,			 0,			 0, 1.0f
		});

		s = Vector3(scaleX, scaleY, scaleZ);
		t = Vector3(M41, M42, M43);
	}

	float Matrix::Determinant() const
	{
		float s0 = M11*M22 - M12*M21;
		float s1 = M11*M23 - M13*M21;
		float s2 = M11*M24 - M14*M21;
		float s3 = M12*M23 - M13*M22;
		float s4 = M12*M24 - M14*M22;
		float s5 = M13*M24 - M14*M23;

		float c0 = M31*M42 - M32*M41;
		float c1 = M31*M43 - M33*M41;
		float c2 = M31*M44 - M34*M41;
		float c3 = M32*M43 - M33*M42;
		float c4 = M32*M44 - M34*M42;
		float c5 = M33*M44 - M34*M43;

		return s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0;
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
		float s = std::sinf(angle);
		float inv = 1.0f - c;

		return Matrix(       axis.X*axis.X*inv + c, axis.X*axis.Y*inv + axis.Z*s, axis.X*axis.Z*inv - axis.Y*s, 0,
					  axis.X*axis.Y*inv - axis.Z*s,        axis.Y*axis.Y*inv + c, axis.Y*axis.Z*inv + axis.X*s, 0,
					  axis.X*axis.Z*inv + axis.Y*s, axis.Y*axis.Z*inv - axis.X*s,        axis.Z*axis.Z*inv + c, 0,
												 0,							   0,							 0, 1.0f);
	}

	Matrix Matrix::CreateFromQuaternion(const Quaternion& q)
	{
		//variables for sanity
		float x = q.X, y = q.Y, z = q.Z, w = q.W;

		return Matrix(1-2*y*y-2*z*z,   2*x*y+2*z*w,   2*x*z-2*y*w,   0,
					    2*x*y-2*z*w, 1-2*x*x-2*z*z,   2*y*z+2*x*w,   0,
					    2*x*z+2*y*w,   2*y*z-2*x*w, 1-2*x*x-2*y*y,   0,
								  0,			 0,		        0, 1.0f);
	}

	Matrix Matrix::CreateFromYawPitchRoll(float y, float p, float r)
	{
		return CreateFromQuaternion(Quaternion::CreateFromYawPitchRoll(y, p, r));
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

	Matrix Matrix::CreatePerspective(float w, float h, float zN, float zF)
	{
		if (zN > zF) throw std::out_of_range("zNear must be less than or equal to zFar");
		if (zN < 0 || zF < 0) throw std::out_of_range("zNear and zFar must be greater than 0");

		return Matrix(2*zN/w,	   0,			  0, 0,
						   0, 2*zN/h,			  0, 0,
						   0,	   0,    zF/(zN-zF), -1.0f,
						   0,	   0, zN*zF/(zN-zF), 0);
	}

	Matrix Matrix::CreatePerspectiveFieldOfView(float fov, float aR, float zN, float zF)
	{
		if (!(fov >= 0 && fov <= MathHelper::Pi)) throw std::out_of_range("fieldOfView must be between 0 and Pi radians (0 and 180 degrees)");
		if (zN > zF) throw std::out_of_range("zNear must be less than or equal to zFar");
		if (zN < 0 || zF < 0) throw std::out_of_range("zNear and zFar must be greater than 0");

		float yScale = std::cos(fov / 2.0f) / std::sin(fov / 2.0f);
		float xScale = yScale / aR;

		return Matrix(xScale,	   0,			  0, 0,
						   0, yScale,			  0, 0,
						   0,	   0,    zF/(zN-zF), -1.0f,
						   0,	   0, zN*zF/(zN-zF), 0);
	}

	Matrix Matrix::CreatePerspectiveOffCenter(float l, float r, float b, float t, float zN, float zF)
	{
		if (zN > zF) throw std::out_of_range("zNear must be less than or equal to zFar");
		if (zN < 0 || zF < 0) throw std::out_of_range("zNear and zFar must be greater than 0");

		return Matrix( 2*zN/(r-l),			 0,             0, 0,
							    0,  2*zN/(t-b),             0, 0,
					  (l+r)/(r-l), (t+b)/(t-b),    zF/(zN-zF), -1.0f,
								0,			 0, zN*zF/(zN-zF), 0);
	}

	Matrix Matrix::CreateReflection(const Plane& p)
	{
		Vector3 n = p.Normal();
		float a = n.X, b = n.Y, c = n.Z, d = p.D();

		float ab = -2*a*b, ac = -2*a*c, ad = -2*a*d, bc = -2*b*c, bd = -2*b*d, cd = -2*c*d;

		return Matrix(-2*a*a+1,		  ab,		ac, 0,
							ab, -2*b*b+1,		bc, 0,
							ac,		  bc, -2*c*c+1, 0,
							ad,		  bd,		cd, 1.0f);
	}

	Matrix Matrix::CreateRotationX(float angle)
	{
		return CreateFromAxisAngle(Vector3::Right, angle);
	}

	Matrix Matrix::CreateRotationY(float angle)
	{
		return CreateFromAxisAngle(Vector3::Up, angle);
	}

	Matrix Matrix::CreateRotationZ(float angle)
	{
		return CreateFromAxisAngle(Vector3::Backward, angle);
	}

	Matrix Matrix::CreateScale(float scale)
	{
		return Matrix(scale,	 0,		0, 0,
					      0, scale,		0, 0,
						  0,	 0, scale, 0,
						  0,	 0,		0, 1.0f);
	}

	Matrix Matrix::CreateScale(float scaleX, float scaleY, float scaleZ)
	{
		return Matrix(scaleX,	   0,      0, 0,
						   0, scaleY,	   0, 0,
						   0,	   0, scaleZ, 0,
						   0,	   0,	   0, 1.0f);
	}

	Matrix Matrix::CreateScale(const Vector3& scaleVec)
	{
		return CreateScale(scaleVec.X, scaleVec.Y, scaleVec.Z);
	}

	Matrix Matrix::CreateShadow(const Vector3& lightDir, const Plane& plane)
	{
		Vector3 l = -lightDir;
		Vector3 pN = plane.Normal();
		float d = plane.D();
		float s = -Vector3::Dot(l, pN);
		return Matrix(pN.X*l.X+s,   pN.X*l.Y,   pN.X*l.Z, 0,
					    pN.Y*l.X, pN.Y*l.Y+s,   pN.Y*l.Z, 0, 
					    pN.Z*l.X,   pN.Z*l.Y, pN.Z*l.Z+s, 0,
					       d*l.X,      d*l.Y,      d*l.Z, s);
	}

	Matrix Matrix::CreateTranslation(float xT, float yT, float zT)
	{
		return Matrix(1.0f,    0,    0, 0,
					     0, 1.0f,    0, 0,
					     0,    0, 1.0f, 0,
					    xT,    yT,  zT, 1.0f);
	}

	Matrix Matrix::CreateTranslation(const Vector3& vec)
	{
		return CreateTranslation(vec.X, vec.Y, vec.Z);
	}

	Matrix Matrix::CreateWorld(Vector3 pos, Vector3 fwd, Vector3 up)
	{
		fwd.Normalize();
		up.Normalize();
		Vector3 r = Vector3::Normalize(Vector3::Cross(fwd, up));

		return Matrix(   r.X,    r.Y,    r.Z, 0,
					    up.X,   up.Y,   up.Z, 0,
					  -fwd.X, -fwd.Y, -fwd.Z, 0,
					   pos.X,  pos.Y,  pos.Z, 1.0f);
	}
}