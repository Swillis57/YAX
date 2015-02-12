#include "../../include/Math/Vector4.h"

#include "../../include/Math/Matrix.h"
#include "../../include/Math/MathHelper.h"
#include "../../include/Math/Quaternion.h"
#include "../../include/Math/Vector2.h"
#include "../../include/Math/Vector3.h"

namespace YAX
{
	const Vector4 One = Vector4(1, 1, 1, 1);
	const Vector4 UnitX = Vector4(1, 0, 0, 0);
	const Vector4 UnitY = Vector4(0, 1, 0, 0);
	const Vector4 UnitZ = Vector4(0, 0, 1, 0);
	const Vector4 UnitW = Vector4(0, 0, 0, 1);
	const Vector4 Zero = Vector4(0, 0, 0, 0);

	Vector4::Vector4(float v)
		: X(v), Y(v), Z(v), W(v)
	{}

	Vector4::Vector4(float x, float y, float z, float w)
		: X(x), Y(y), Z(z), W(w)
	{}

	Vector4::Vector4(Vector2 xy, float z, float w)
		: Vector4(xy.X, xy.Y, z, w)
	{}

	Vector4::Vector4(Vector3 xyz, float w)
		: Vector4(xyz.X, xyz.Y, xyz.Z, w)
	{}


}