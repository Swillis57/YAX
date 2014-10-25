#ifndef _RAY_H
#define _RAY_H

#include "../Math/Vector3.h"
#include "../Utils.h"
#include <memory>

namespace XNA
{
	class BoundingSphere;
	class BoundingBox;
	class BoundingFrustum;
	class Plane;

	struct Ray
	{
		Vector3 Direction, Position;

		Ray(const Vector3&, const Vector3&);
		std::unique_ptr<float> Intersects(const BoundingBox&);
		std::unique_ptr<float> Intersects(const BoundingFrustum&);
		std::unique_ptr<float> Intersects(const BoundingSphere&);
		std::unique_ptr<float> Intersects(const Plane&);

		bool operator==(const Ray&);
		bool operator!=(const Ray&);

	};
}


#endif