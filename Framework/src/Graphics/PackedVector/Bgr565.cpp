#include "../../../include/Graphics/PackedVector/Bgr565.h"
#include "../../../include/Math/Vector3.h"
#include "../../../include/Math/Vector4.h"

namespace YAX
{
	Bgr565::Bgr565(float b, float g, float r)
		: Bgr565::Base()
	{
		Pack(b, g, r);
	}

	Bgr565::Bgr565(const Vector3& source)
		: Bgr565(source.Z, source.Y, source.X)
	{}

	Bgr565::~Bgr565() = default;

	Vector3 Bgr565::ToVector3() const
	{
		return Vector3
		(
			READBITS(0x1F, 11) / 32.0f,
			READBITS(0x3F, 5) / 64.0f,
			READBITS(0x1F, 0) / 32.0f
		);
	}

	Vector4 Bgr565::ToVector4() const
	{
		return Vector4(ToVector3(), 1.0f);
	}

	void Bgr565::PackFromVector4(const Vector4& source)
	{
		Pack(source.X, source.Y, source.Z);
	}

	bool operator==(const Bgr565& lhs, const Bgr565& rhs)
	{
		return (lhs._packed == rhs._packed);
	}

	bool operator!=(const Bgr565& lhs, const Bgr565& rhs)
	{
		return !(lhs == rhs);
	}

	void Bgr565::Pack(float b, float g, float r)
	{
		byte redBits = r * 32;
		byte greenBits = g * 64;
		byte blueBits = b * 32;

		_packed ^= _packed;
		WRITEBITS(blueBits, 6)
		WRITEBITS(greenBits, 5)
		WRITEBITS(blueBits, 0);
	}
	
}