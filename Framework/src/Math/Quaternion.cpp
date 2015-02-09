#include "../../include/Math/Quaternion.h"

#include "../../include/Math/MathHelper.h" 
#include "../../include/Math/Matrix.h"
#include "../../include/Math/Vector3.h"

namespace YAX
{
	const Quaternion Quaternion::Identity(0, 0, 0, 1.0f);

	Quaternion::Quaternion(float x, float y, float z, float w)
		: X(x), Y(y), Z(z), W(w)
	{}

	Quaternion::Quaternion(Vector3 xyz, float w)
		: Quaternion(xyz.X, xyz.Y, xyz.Z, w)
	{}
}
