#include "../../../include/Graphics/PackedVector/Bgra5551.h"
#include "../../../include/Math/Vector4.h"

namespace YAX
{
	Bgra5551::Bgra5551(float b, float g, float r, float a)
		: Bgra5551::Base()
	{
		Pack(b, g, r, a);
	}

	Bgra5551::Bgra5551(const Vector4& source)
		: Bgra5551(source.X, source.Y, source.Z, source.W)
	{}

	Bgra5551::~Bgra5551() = default;

	Vector4 Bgra5551::ToVector4() const
	{
		return Vector4
		(
			READBITS(0x1F, 11) / 32.0f,
			READBITS(0x1F, 6) / 32.0f,
			READBITS(0x1F, 1) / 32.0f,
			READBITS(0x1, 0)
		);
	}

	void Bgra5551::PackFromVector4(const Vector4& source)
	{
		Pack(source.X, source.Y, source.Z, source.W);
	}

	bool operator==(const Bgra5551& lhs, const Bgra5551& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const Bgra5551& lhs, const Bgra5551& rhs)
	{
		return !(lhs == rhs);
	}

	void Bgra5551::Pack(float b, float g, float r, float a)
	{
		byte blueBits = b * 32;
		byte greenBits = g * 32;
		byte redBits = r * 32;
		byte alphaBits = a * 10;
		if (alphaBits > 0) alphaBits = 0x1;

		_packed ^= _packed;
		WRITEBITS(blueBits, 5);
		WRITEBITS(greenBits, 5);
		WRITEBITS(redBits, 1);
		WRITEBITS(alphaBits, 0);
	}
}
