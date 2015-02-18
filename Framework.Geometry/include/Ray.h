#ifndef _RAY_H
#define _RAY_H

#include <memory>
#include "../../Framework.Math/include/Vector3.h"

namespace YAX
{
	class BoundingSphere;
	class BoundingBox;
	class BoundingFrustum;
	class Plane;

	struct Ray
	{
		Ray(const Vector3&, const Vector3&);
	
		Vector3 Direction();
		void Direction(const Vector3&);

		Vector3 Position();
		void Position(const Vector3&);

		std::unique_ptr<float> Intersects(const BoundingBox&);
		std::unique_ptr<float> Intersects(const BoundingFrustum&);
		std::unique_ptr<float> Intersects(const BoundingSphere&);
		std::unique_ptr<float> Intersects(const Plane&);

		friend bool operator==(const Ray&, const Ray&);
		friend bool operator!=(const Ray&, const Ray&);

	private:
		Vector3 _dir, _pos;
	};
}


#endif