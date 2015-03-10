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
}