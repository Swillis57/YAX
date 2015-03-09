#ifndef _RAY_H
#define _RAY_H

#include <memory>
#include "../../Framework.Math/include/Vector3.h"

namespace YAX
{
	struct BoundingSphere;
	struct BoundingBox;
	struct Plane;
	class BoundingFrustum;

	struct Ray
	{
		Ray(const Vector3&, const Vector3&);
	
		Vector3 Dir, Pos;

		std::unique_ptr<float> Intersects(const BoundingBox&);
		std::unique_ptr<float> Intersects(const BoundingFrustum&);
		std::unique_ptr<float> Intersects(const BoundingSphere&);
		std::unique_ptr<float> Intersects(const Plane&);

		friend bool operator==(const Ray&, const Ray&);
		friend bool operator!=(const Ray&, const Ray&);
	};
}


#endif