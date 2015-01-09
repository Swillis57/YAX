#include "../../../include/Graphics/PackedVector/Bgr565.h"
#include "../../../include/Math/Vector3.h"
#include "../../../include/Math/Vector4.h"

namespace YAX
{
	Bgr565::Bgr565(float r, float g, float b)
	{
		byte redBits = r * 32;
		byte greenBits = g * 64;
		byte blueBits = b * 32;

		_packed &= blueBits;
		_packed <<= 6;
		_packed &= greenBits;
		_packed <<= 5;
		_packed &= redBits;
	}

	Bgr565::Bgr565(const Vector3& source)
		: Bgr565(source.X(), source.Y(), source.Z())
	{}

	Vector3 Bgr565::ToVector3() const
	{
		return Vector3
		(
			READBITS(32, 0),
			READBITS(64, 5),
			READBITS(32, 11)
		);
	}

	Vector4 Bgr565::ToVector4() const
	{
		return Vector4(ToVector3(), 1.0f);
	}

	void Bgr565::PackFromVector4(const Vector4& source)
	{
		byte redBits = source.X() * 32;
		byte greenBits = source.Y() * 64;
		byte blueBits = source.Z() * 32;

		_packed &= blueBits;
		_packed <<= 6;
		_packed &= greenBits;
		_packed <<= 5;
		_packed &= redBits;
	}

	bool operator==(const Bgr565& lhs, const Bgr565& rhs)
	{
		return (lhs._packed == rhs._packed);
	}

	bool operator!=(const Bgr565& lhs, const Bgr565& rhs)
	{
		return !(lhs == rhs);
	}
	
}