#include "../include/Rgba64.h"
#include "../../Framework.Math/include/MathHelper.h"
#include "../../Framework.Math/include/Vector4.h"

namespace YAX
{
	Rgba64::Rgba64(float r, float g, float b, float a)
		: Base()
	{
		Pack(r, g, b, a);
	}

	Rgba64::Rgba64(const Vector4& v)
		: Rgba64(v.X, v.Y, v.Z, v.W)
	{}

	Rgba64::~Rgba64() = default;

	Vector4 Rgba64::ToVector4() const
	{
		ui16 r = READBITS(0xFFFF, 48);
		ui16 g = READBITS(0xFFFF, 32);
		ui16 b = READBITS(0xFFFF, 16);
		ui16 a = READBITS(0xFFFF, 0);

		return Vector4
		(
			r / 65536.0f,
			g / 65536.0f,
			b / 65536.0f,
			a / 65536.0f
		);
	}

	void Rgba64::PackFromVector4(const Vector4& v)
	{
		Pack(v.X, v.Y, v.Z, v.W);
	}

	void Rgba64::Pack(float r, float g, float b, float a)
	{
		using MathHelper::Clamp;

		ui16 rBits = static_cast<ui16>(Clamp(r, 0, 1) * 65536);
		ui16 gBits = static_cast<ui16>(Clamp(r, 0, 1) * 65536);
		ui16 bBits = static_cast<ui16>(Clamp(r, 0, 1) * 65536);
		ui16 aBits = static_cast<ui16>(Clamp(r, 0, 1) * 65536);

		WRITEBITS(rBits, 48);
		WRITEBITS(gBits, 32);
		WRITEBITS(bBits, 16);
		WRITEBITS(aBits, 0);
	}

	bool operator==(const Rgba64& lhs, const Rgba64& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const Rgba64& lhs, const Rgba64& rhs)
	{
		return !(lhs == rhs);
	}


}