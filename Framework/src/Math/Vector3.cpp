#include "../../include/Math/Vector3.h"

#include "../../include/Math/Vector2.h"
#include "../../include/Math/Matrix.h"
#include "../../include/Math/Quaternion.h"

namespace YAX
{	
	const Vector3 Vector3::One = Vector3(1.0f);
	const Vector3 Vector3::UnitX = Vector3(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::UnitY = Vector3(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::UnitZ = Vector3(0.0f, 0.0f, 1.0f);
	const Vector3 Vector3::Backward = Vector3::UnitZ;
	const Vector3 Vector3::Down = -Vector3::UnitY;
	const Vector3 Vector3::Forward = -Vector3::UnitZ;
	const Vector3 Vector3::Left = -Vector3::UnitX;
	const Vector3 Vector3::Right = Vector3::UnitX;
	const Vector3 Vector3::Up = Vector3::UnitY;
}