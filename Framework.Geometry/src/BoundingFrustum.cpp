#include "../include/BoundingFrustum.h"

#include "../include/BoundingBox.h"
#include "../include/BoundingSphere.h"
#include "../include/ContainmentType.h"
#include "../include/Plane.h"
#include "../include/PlaneIntersectionType.h"
#include "../include/Ray.h"
#include "../../Framework.Math/include/Vector3.h"



namespace YAX
{
	BoundingFrustum::BoundingFrustum(YAX::Matrix m)
		: Matrix(m)
	{}

	Plane BoundingFrustum::Bottom() const
	{
		Vector3 n(Matrix.M12 + Matrix.M14,
				  Matrix.M22 + Matrix.M24,
				  Matrix.M32 + Matrix.M34);
		
		//When the plane equation is normalized,
		//d is the distance from the origin to the plane
		float d = Matrix.M42 + Matrix.M44;
		float len = n.Length();

		//normalize the plane equation
		n /= len;
		d /= len;
		
		return Plane(n, d);
	}

	Plane BoundingFrustum::Far() const
	{
		Vector3 n(Matrix.M14 - Matrix.M13,
				  Matrix.M24 - Matrix.M23,
				  Matrix.M34 - Matrix.M33);
		
		//When the plane equation is normalized,
		//d is the distance from the origin to the plane
		float d = Matrix.M44 - Matrix.M43;
		float len = n.Length();

		//normalize the plane equation
		n /= len;
		d /= len;
		
		return Plane(n, d);
	}

	Plane BoundingFrustum::Left() const
	{
		Vector3 n(Matrix.M14 + Matrix.M11,
				  Matrix.M24 + Matrix.M21,
				  Matrix.M34 + Matrix.M31);
		
		//When the plane equation is normalized,
		//d is the distance from the origin to the plane
		float d = Matrix.M44 + Matrix.M41;
		float len = n.Length();

		//normalize the plane equation
		n /= len;
		d /= len;
		
		return Plane(n, d);
	}

	Plane BoundingFrustum::Near() const
	{
		Vector3 n(Matrix.M13,
				  Matrix.M23,
				  Matrix.M33);
		
		//When the plane equation is normalized,
		//d is the distance from the origin to the plane
		float d = Matrix.M43;
		float len = n.Length();

		//normalize the plane equation
		n /= len;
		d /= len;
		
		return Plane(n, d);
	}

	Plane BoundingFrustum::Right() const
	{
		Vector3 n(Matrix.M14 - Matrix.M11,
				  Matrix.M24 - Matrix.M21,
				  Matrix.M34 - Matrix.M31);
		
		//When the plane equation is normalized,
		//d is the distance from the origin to the plane
		float d = Matrix.M44 - Matrix.M41;
		float len = n.Length();

		//normalize the plane equation
		n /= len;
		d /= len;
		
		return Plane(n, d);
	}

	Plane BoundingFrustum::Top() const
	{
		Vector3 n(Matrix.M14 - Matrix.M12,
				  Matrix.M24 - Matrix.M22,
				  Matrix.M34 - Matrix.M32);
		
		//When the plane equation is normalized,
		//d is the distance from the origin to the plane
		float d = Matrix.M44 - Matrix.M42;
		float len = n.Length();

		//normalize the plane equation
		n /= len;
		d /= len;
		
		return Plane(n, d);
	}
}