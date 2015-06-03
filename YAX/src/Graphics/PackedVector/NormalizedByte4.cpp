#include "../include/NormalizedByte4.h"
#include "../../YAX.Math/include/MathHelper.h"
#include "../../YAX.Math/include/Vector4.h"


namespace YAX
{
	NormalizedByte4::NormalizedByte4(float val1, float val2, float val3, float val4)
		: NormalizedByte4::Base()
	{
			Pack(val1, val2, val3, val4);
	}

	NormalizedByte4::NormalizedByte4(const Vector4& source)
		: NormalizedByte4(source.X, source.Y, source.Z, source.W)
	{}

	NormalizedByte4::~NormalizedByte4() = default;

	Vector4 NormalizedByte4::ToVector4() const
	{
		byte val1 = READBITS(0xFF, 24);
		byte val2 = READBITS(0xFF, 16);
		byte val3 = READBITS(0xFF, 8);
		byte val4 = READBITS(0xFF, 0);

		return Vector4
		(
			BitCast<signed char>(val1) / 128.0f,
			BitCast<signed char>(val2) / 128.0f,
			BitCast<signed char>(val3) / 128.0f,
			BitCast<signed char>(val4) / 128.0f
		);
	}

	void NormalizedByte4::PackFromVector4(const Vector4& source)
	{
		Pack(source.X, source.Y, source.Z, source.W);
	}

	bool operator==(const NormalizedByte4& lhs, const NormalizedByte4& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const NormalizedByte4& lhs, const NormalizedByte4& rhs)
	{
		return !(lhs == rhs);
	}

	void NormalizedByte4::Pack(float val1, float val2, float val3, float val4)
	{
		using MathHelper::Clamp;

		auto val1Fixed = static_cast<signed char>(Clamp(val1, -1, 1) * 128);
		auto val2Fixed = static_cast<signed char>(Clamp(val2, -1, 1) * 128);
		auto val3Fixed = static_cast<signed char>(Clamp(val3, -1, 1) * 128);
		auto val4Fixed = static_cast<signed char>(Clamp(val4, -1, 1) * 128);
		
		_packed ^= _packed;
		WRITEBITS(val1Fixed, 8);
		WRITEBITS(val2Fixed, 8);
		WRITEBITS(val3Fixed, 8);
		WRITEBITS(val4Fixed, 0);
	}
}