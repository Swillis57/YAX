#include "../../../include/Graphics/PackedVector/Bgra4444.h"
#include "../../../include/Math/Vector4.h"

namespace YAX
{
	Bgra4444::Bgra4444(float b, float g, float r, float a)
		: Bgra4444::Base()
	{
		Pack(b, g, r, a);
	}

	Bgra4444::Bgra4444(const Vector4& source)
		: Bgra4444(source.Z, source.Y, source.X, source.W)
	{}

	Bgra4444::~Bgra4444() = default;

	Vector4 Bgra4444::ToVector4() const
	{
		return Vector4
		(
			READBITS(0xF, 12) / 16.0f,
			READBITS(0xF, 8) / 16.0f,
			READBITS(0xF, 4) / 16.0f,
			READBITS(0xF, 0) / 16.0f
		);
	}

	void Bgra4444::PackFromVector4(const Vector4& source)
	{
		Pack(source.X, source.Y, source.Z, source.W);
	}

	bool operator==(const Bgra4444& lhs, const Bgra4444& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const Bgra4444& lhs, const Bgra4444& rhs)
	{
		return !(lhs == rhs);
	}

	void Bgra4444::Pack(float b, float g, float r, float a)
	{
		byte blueBits = b * 16;
		byte greenBits = g * 16;
		byte redBits = r * 16;
		byte alphaBits = a * 16;

		_packed ^= _packed;
		WRITEBITS(blueBits, 4);
		WRITEBITS(greenBits, 4);
		WRITEBITS(redBits, 4);
		WRITEBITS(alphaBits, 4);
	}

}