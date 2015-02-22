#include "../include/NormalizedShort4.h"
#include "../../Framework.Math/include/MathHelper.h"
#include "../../Framework.Math/include/Vector4.h"

namespace YAX
{
	NormalizedShort4::NormalizedShort4(float v1, float v2, float v3, float v4)
		: Base()
	{
		Pack(v1, v2, v3, v4);
	}

	NormalizedShort4::NormalizedShort4(const Vector4& v)
		: NormalizedShort4(v.X, v.Y, v.Z, v.W)
	{}

	NormalizedShort4::~NormalizedShort4() = default;

	Vector4 NormalizedShort4::ToVector4() const
	{
		ui16 s1 = READBITS(0xFFFF, 48);
		ui16 s2 = READBITS(0xFFFF, 32);
		ui16 s3 = READBITS(0xFFFF, 16);
		ui16 s4 = READBITS(0xFFFF, 0);

		return Vector4
		(
			BitCast<i16>(s1) / 32676.0f,
			BitCast<i16>(s2) / 32676.0f,
			BitCast<i16>(s3) / 32676.0f,
			BitCast<i16>(s4) / 32676.0f
		);
	}

	void NormalizedShort4::PackFromVector4(const Vector4& v)
	{
		Pack(v.X, v.Y, v.Z, v.W);
	}

	bool operator==(const NormalizedShort4& lhs, const NormalizedShort4& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const NormalizedShort4& lhs, const NormalizedShort4& rhs)
	{
		return !(lhs == rhs);
	}

	void NormalizedShort4::Pack(float v1, float v2, float v3, float v4)
	{
		using MathHelper::Clamp;

		auto s1 = static_cast<i16>(Clamp(v1, -1, 1) * 32767);
		auto s2 = static_cast<i16>(Clamp(v2, -1, 1) * 32767);
		auto s3 = static_cast<i16>(Clamp(v3, -1, 1) * 32767);
		auto s4 = static_cast<i16>(Clamp(v4, -1, 1) * 32767);
		
		_packed ^= _packed;
		WRITEBITS(BitCast<unsigned short>(s1), 16);
		WRITEBITS(BitCast<unsigned short>(s2), 16);
		WRITEBITS(BitCast<unsigned short>(s3), 16);
		WRITEBITS(BitCast<unsigned short>(s4), 0);
	}
}