#include "../include/Short4.h"
#include "../../YAX.Math/include/Vector4.h"

namespace YAX
{
	Short4::Short4(float s1, float s2, float s3, float s4)
		: Base()
	{
		Pack(s1, s2, s3, s4);
	}

	Short4::Short4(const Vector4& v)
		: Short4(v.X, v.Y, v.Z, v.W)
	{}

	Short4::~Short4() = default;

	Vector4 Short4::ToVector4() const
	{
		ui64 mask = 0xFFFF;

		ui16 s1Bits = static_cast<ui16>(READBITS(mask, 48));
		ui16 s2Bits = static_cast<ui16>(READBITS(mask, 32));
		ui16 s3Bits = static_cast<ui16>(READBITS(mask, 16));
		ui16 s4Bits = static_cast<ui16>(READBITS(mask, 0));

		return Vector4
		(
			BitCast<i16>(s1Bits),
			BitCast<i16>(s2Bits),
			BitCast<i16>(s3Bits),
			BitCast<i16>(s4Bits)
		);
	}

	void Short4::PackFromVector4(const Vector4& v)
	{
		Pack(v.X, v.Y, v.Z, v.W);
	}

	void Short4::Pack(float s1, float s2, float s3, float s4)
	{
		i16 s1Fixed = static_cast<i16>(s1);
		i16 s2Fixed = static_cast<i16>(s2);
		i16 s3Fixed = static_cast<i16>(s3);
		i16 s4Fixed = static_cast<i16>(s4);

		WRITEBITS(s1Fixed, 16);
		WRITEBITS(s2Fixed, 16);
		WRITEBITS(s3Fixed, 16);
		WRITEBITS(s4Fixed, 0);
	}

	bool operator==(const Short4& lhs, const Short4& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const Short4& lhs, const Short4& rhs)
	{
		return !(lhs == rhs);
	}
}
