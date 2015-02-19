#include <cmath>
#include "../include/Byte4.h"
#include "../../Framework.Math/include/MathHelper.h"
#include "../../Framework.Math/include/Vector4.h"

namespace YAX
{
	Byte4::Byte4(float r, float g, float b, float a)
		: Byte4::Base()
	{
		Pack(r, g, b, a);
	}

	Byte4::Byte4(const Vector4& source)
		: Byte4(source.X, source.Y, source.Z, source.W)
	{}

	Byte4::~Byte4() = default;

	Vector4 Byte4::ToVector4() const
	{
		return Vector4
		(
			static_cast<float>(READBITS(0xFF, 24)),
			static_cast<float>(READBITS(0xFF, 16)),
			static_cast<float>(READBITS(0xFF, 8)),
			static_cast<float>(READBITS(0xFF, 0))
		);
	}

	void Byte4::PackFromVector4(const Vector4& source)
	{
		Pack(source.X, source.Y, source.Z, source.W);
	}

	bool operator==(const Byte4& lhs, const Byte4& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const Byte4 lhs, const Byte4& rhs)
	{
		return !(lhs == rhs);
	}

	void Byte4::Pack(float r, float b, float g, float a)
	{
		using std::round;
		using MathHelper::Clamp;

		byte redBits = static_cast<byte>(Clamp(round(r), 0, 255));
		byte greenBits = static_cast<byte>(Clamp(round(g), 0, 255));
		byte blueBits = static_cast<byte>(Clamp(round(b), 0, 255));
		byte alphaBits = static_cast<byte>(Clamp(round(a), 0, 255)); 

		_packed ^= _packed;
		WRITEBITS(redBits, 8);
		WRITEBITS(greenBits, 8);
		WRITEBITS(blueBits, 8);
		WRITEBITS(alphaBits, 0);
	}
}