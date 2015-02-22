#include "../include/NormalizedShort2.h"
#include "../../Framework.Math/include/MathHelper.h"
#include "../../Framework.Math/include/Vector2.h"
#include "../../Framework.Math/include/Vector4.h"

namespace YAX
{
	NormalizedShort2::NormalizedShort2(float val1, float val2)
		: NormalizedShort2::Base()
	{
		Pack(val1, val2);
	}

	NormalizedShort2::NormalizedShort2(const Vector2& source)
		: NormalizedShort2(source.X, source.Y)
	{}

	NormalizedShort2::~NormalizedShort2() = default;

	Vector2 NormalizedShort2::ToVector2() const
	{
		ui16 s1 = READBITS(0xFFFF, 16);
		ui16 s2 = READBITS(0xFFFF, 0);

		return Vector2
		(
			BitCast<i16>(s1) / 32767.0f, 
			BitCast<i16>(s2) / 32767.0f
		);
	}				   

	Vector4 NormalizedShort2::ToVector4() const
	{
		return Vector4(ToVector2(), 0.0f, 1.0f);
	}

	void NormalizedShort2::PackFromVector4(const Vector4& source)
	{
		Pack(source.X, source.Y);
	}

	bool operator==(const NormalizedShort2& lhs, const NormalizedShort2& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const NormalizedShort2& lhs, const NormalizedShort2& rhs)
	{
		return !(lhs == rhs);
	}

	void NormalizedShort2::Pack(float val1, float val2)
	{
		using MathHelper::Clamp;

		auto val1Fixed = static_cast<i16>(Clamp(val1, -1, 1) * 32767);
		auto val2Fixed = static_cast<i16>(Clamp(val2, -1, 1) * 32767);

		_packed ^= _packed;
		WRITEBITS(BitCast<unsigned short>(val1Fixed), 16);
		WRITEBITS(BitCast<unsigned short>(val2Fixed), 0);
	}
}