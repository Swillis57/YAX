#include "../include/NormalizedShort2.h"
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
		return Vector2
		(
			static_cast<signed short>(READBITS(0xFFFF, 16)) / 65536.0f, 
			static_cast<signed short>(READBITS(0xFFFF, 0)) / 65536.0f
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
		auto val1Fixed = static_cast<signed short>(val1 * 65536);
		auto val2Fixed = static_cast<signed short>(val2 * 65536);

		_packed ^= _packed;
		WRITEBITS(BitCast<unsigned short>(val1Fixed), 16);
		WRITEBITS(BitCast<unsigned short>(val2Fixed), 0);
	}
}