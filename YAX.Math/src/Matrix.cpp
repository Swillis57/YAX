#include "../include/Matrix.h"
#include <exception>
#include "../../YAX.Geometry/include/Plane.h"
#include "../include/MathHelper.h"
#include "../include/Quaternion.h"
#include "../include/Vector3.h"

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

		return true;
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
		Vector3 zBasis = Vector3::Normalize(cameraTarg - cameraPos);
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
		Vector3 n = p.Normal;
		float a = n.X, b = n.Y, c = n.Z, d = p.D;

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
		Vector3 pN = plane.Normal;
		float d = plane.D;
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

	Matrix Matrix::Invert(const Matrix& m)
	{
		float s0 = m.M11*m.M22 - m.M12*m.M21;
		float s1 = m.M11*m.M23 - m.M13*m.M21;
		float s2 = m.M11*m.M24 - m.M14*m.M21;
		float s3 = m.M12*m.M23 - m.M13*m.M22;
		float s4 = m.M12*m.M24 - m.M14*m.M22;
		float s5 = m.M13*m.M24 - m.M14*m.M23;
	
		float c0 = m.M31*m.M42 - m.M32*m.M41;
		float c1 = m.M31*m.M43 - m.M33*m.M41;
		float c2 = m.M31*m.M44 - m.M34*m.M41;
		float c3 = m.M32*m.M43 - m.M33*m.M42;
		float c4 = m.M32*m.M44 - m.M34*m.M42;
		float c5 = m.M33*m.M44 - m.M34*m.M43;

		float det = s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0;

		Matrix adj(m.M22*c5 - m.M23*c4 + m.M24*c3, -m.M12*c5 + m.M13*c4 - m.M14*c3, m.M42*s5 - m.M43*s4 + m.M44*s3, -m.M32*s5 + m.M33*s4 - m.M34*s3,
				   -m.M21*c5 + m.M23*c2 - m.M24*c1, m.M11*c5 - m.M13*c2 + m.M14*c1, -m.M41*s5 + m.M43*s2 - m.M44*s1, m.M31*s5 - m.M33*s2 + m.M34*s1,
				   m.M21*c4 - m.M22*c2 + m.M24*c0, -m.M11*c4 + m.M12*c2 - m.M14*c0, m.M41*s4 - m.M42*s2 + m.M44*s0, -m.M31*s4 + m.M32*s2 - m.M34*s0,
				   -m.M21*c3 + m.M22*c1 - m.M23*c0, m.M11*c3 - m.M12*c1 + m.M13*c0, -m.M41*s3 + m.M42*s1 - m.M43*s0, m.M31*s3 - m.M32*s1 + m.M33*s0);

		return (1 / det)*adj;
	}

	Matrix Matrix::Lerp(const Matrix& from, const Matrix& to, float t)
	{
		return Matrix(MathHelper::Lerp(from.M11, to.M11, t),
					  MathHelper::Lerp(from.M12, to.M12, t),
					  MathHelper::Lerp(from.M13, to.M13, t),
					  MathHelper::Lerp(from.M14, to.M14, t),
					  MathHelper::Lerp(from.M21, to.M21, t),
					  MathHelper::Lerp(from.M22, to.M22, t),
					  MathHelper::Lerp(from.M23, to.M23, t),
					  MathHelper::Lerp(from.M24, to.M24, t),
					  MathHelper::Lerp(from.M31, to.M31, t),
					  MathHelper::Lerp(from.M32, to.M32, t),
					  MathHelper::Lerp(from.M33, to.M33, t),
					  MathHelper::Lerp(from.M34, to.M34, t),
					  MathHelper::Lerp(from.M41, to.M41, t),
					  MathHelper::Lerp(from.M42, to.M42, t),
					  MathHelper::Lerp(from.M43, to.M43, t),
					  MathHelper::Lerp(from.M44, to.M44, t));
	}

	Matrix Matrix::Transform(const Matrix& m, const Quaternion& r)
	{
		return m*CreateFromQuaternion(r);
	}

	Matrix Matrix::Transpose(const Matrix& m)
	{
		return Matrix(m.M11, m.M21, m.M31, m.M41,
					  m.M12, m.M22, m.M32, m.M42,
					  m.M13, m.M23, m.M33, m.M43,
					  m.M14, m.M24, m.M34, m.M44);
	}

	Matrix& Matrix::operator+=(const Matrix& m)
	{
		this->M11 += m.M11;
		this->M12 += m.M12;
		this->M13 += m.M13;
		this->M14 += m.M14;
		this->M21 += m.M21;
		this->M22 += m.M22;
		this->M23 += m.M23;
		this->M24 += m.M24;
		this->M31 += m.M31;
		this->M32 += m.M32;
		this->M33 += m.M33;
		this->M34 += m.M34;
		this->M41 += m.M41;
		this->M42 += m.M42;
		this->M43 += m.M43;
		this->M44 += m.M44;

		return *this;
	}

	Matrix& Matrix::operator-=(const Matrix& m)
	{
		this->M11 -= m.M11;
		this->M12 -= m.M12;
		this->M13 -= m.M13;
		this->M14 -= m.M14;
		this->M21 -= m.M21;
		this->M22 -= m.M22;
		this->M23 -= m.M23;
		this->M24 -= m.M24;
		this->M31 -= m.M31;
		this->M32 -= m.M32;
		this->M33 -= m.M33;
		this->M34 -= m.M34;
		this->M41 -= m.M41;
		this->M42 -= m.M42;
		this->M43 -= m.M43;
		this->M44 -= m.M44;

		return *this;
	}

	Matrix& Matrix::operator*=(const Matrix& m)
	{
		float m11 = M11*m.M11 + M12*m.M21 + M13*m.M31 + M14*m.M41;
		float m12 = M11*m.M12 + M12*m.M22 + M13*m.M32 + M14*m.M42;
		float m13 = M11*m.M13 + M12*m.M23 + M13*m.M33 + M14*m.M43;
		float m14 = M11*m.M14 + M12*m.M24 + M13*m.M34 + M14*m.M44;
		float m21 = M21*m.M11 + M22*m.M21 + M23*m.M31 + M24*m.M41;
		float m22 = M21*m.M12 + M22*m.M22 + M23*m.M32 + M24*m.M42;
		float m23 = M21*m.M13 + M22*m.M23 + M23*m.M33 + M24*m.M43;
		float m24 = M21*m.M14 + M22*m.M24 + M23*m.M34 + M24*m.M44;
		float m31 = M31*m.M11 + M32*m.M21 + M33*m.M31 + M34*m.M41;
		float m32 = M31*m.M12 + M32*m.M22 + M33*m.M32 + M34*m.M42;
		float m33 = M31*m.M13 + M32*m.M23 + M33*m.M33 + M34*m.M43;
		float m34 = M31*m.M14 + M32*m.M24 + M33*m.M34 + M34*m.M44;
		float m41 = M41*m.M11 + M42*m.M21 + M43*m.M31 + M44*m.M41;
		float m42 = M41*m.M12 + M42*m.M22 + M43*m.M32 + M44*m.M42;
		float m43 = M41*m.M13 + M42*m.M23 + M43*m.M33 + M44*m.M43;
		float m44 = M41*m.M14 + M42*m.M24 + M43*m.M34 + M44*m.M44;

		this->M11 = m11;
		this->M12 = m12;
		this->M13 = m13;
		this->M14 = m14;
		this->M21 = m21;
		this->M22 = m22;
		this->M23 = m23;
		this->M24 = m24;
		this->M31 = m31;
		this->M32 = m32;
		this->M33 = m33;
		this->M34 = m34;
		this->M41 = m41;
		this->M42 = m42;
		this->M43 = m43;
		this->M44 = m44;
		

		return *this;
	}

	Matrix& Matrix::operator*=(float f)
	{
		this->M11 *= f;
		this->M12 *= f;
		this->M13 *= f;
		this->M14 *= f;
		this->M21 *= f;
		this->M22 *= f;
		this->M23 *= f;
		this->M24 *= f;
		this->M31 *= f;
		this->M32 *= f;
		this->M33 *= f;
		this->M34 *= f;
		this->M41 *= f;
		this->M42 *= f;
		this->M43 *= f;
		this->M44 *= f;

		return *this;
	}

	Matrix& Matrix::operator/=(const Matrix& m)
	{
		this->M11 /= m.M11;
		this->M12 /= m.M12;
		this->M13 /= m.M13;
		this->M14 /= m.M14;
		this->M21 /= m.M21;
		this->M22 /= m.M22;
		this->M23 /= m.M23;
		this->M24 /= m.M24;
		this->M31 /= m.M31;
		this->M32 /= m.M32;
		this->M33 /= m.M33;
		this->M34 /= m.M34;
		this->M41 /= m.M41;
		this->M42 /= m.M42;
		this->M43 /= m.M43;
		this->M44 /= m.M44;

		return *this;
	}

	Matrix& Matrix::operator/=(float f)
	{
		this->M11 /= f;
		this->M12 /= f;
		this->M13 /= f;
		this->M14 /= f;
		this->M21 /= f;
		this->M22 /= f;
		this->M23 /= f;
		this->M24 /= f;
		this->M31 /= f;
		this->M32 /= f;
		this->M33 /= f;
		this->M34 /= f;
		this->M41 /= f;
		this->M42 /= f;
		this->M43 /= f;
		this->M44 /= f;

		return *this;
	}

	Matrix operator+(Matrix lhs, const Matrix& rhs)
	{
		lhs += rhs;
		return lhs;
	}

	Matrix operator-(Matrix lhs, const Matrix& rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	Matrix operator*(Matrix lhs, const Matrix& rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	Matrix operator*(float lhs, const Matrix& rhs)
	{
		return rhs*lhs;
	}

	Matrix operator*(Matrix lhs, float rhs)
	{
		lhs *= rhs;
		return lhs;
	}

	Matrix operator/(Matrix lhs, const Matrix& rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	Matrix operator/(Matrix lhs, float rhs)
	{
		lhs /= rhs;
		return lhs;
	}

	Matrix operator-(Matrix rhs)
	{
		rhs.M11 = -rhs.M11;
		rhs.M12 = -rhs.M12;
		rhs.M13 = -rhs.M13;
		rhs.M14 = -rhs.M14;
		rhs.M21 = -rhs.M21;
		rhs.M22 = -rhs.M22;
		rhs.M23 = -rhs.M23;
		rhs.M24 = -rhs.M24;
		rhs.M31 = -rhs.M31;
		rhs.M32 = -rhs.M32;
		rhs.M33 = -rhs.M33;
		rhs.M34 = -rhs.M34;
		rhs.M41 = -rhs.M41;
		rhs.M42 = -rhs.M42;
		rhs.M43 = -rhs.M43;
		rhs.M44 = -rhs.M44;

		return rhs;
	}

	bool operator==(const Matrix& lhs, const Matrix& rhs)
	{
		return lhs.M11 == rhs.M11 &&
			   lhs.M12 == rhs.M12 &&
			   lhs.M13 == rhs.M13 &&
			   lhs.M14 == rhs.M14 &&
			   lhs.M21 == rhs.M21 &&
			   lhs.M22 == rhs.M22 &&
			   lhs.M23 == rhs.M23 &&
			   lhs.M24 == rhs.M24 &&
			   lhs.M31 == rhs.M31 &&
			   lhs.M32 == rhs.M32 &&
			   lhs.M33 == rhs.M33 &&
			   lhs.M34 == rhs.M34 &&
			   lhs.M41 == rhs.M41 &&
			   lhs.M42 == rhs.M42 &&
			   lhs.M43 == rhs.M43 &&
			   lhs.M44 == rhs.M44;
	}

	bool operator!=(const Matrix& lhs, const Matrix& rhs)
	{
		return !(lhs == rhs);
	}
}