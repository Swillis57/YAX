#include "../include/NormalizedShort4.h"
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
		const ui64 mask = 0xFFFF;

		float v1 = READBITS(mask, 48) / 65536.0f;
		float v2 = READBITS(mask, 32) / 65536.0f;
		float v3 = READBITS(mask, 16) / 65536.0f;
		float v4 = READBITS(mask, 0) / 65536.0f;

		return Vector4(v1, v2, v3, v4);
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
		auto s1 = static_cast<signed short>(v1 * 65536);
		auto s2 = static_cast<signed short>(v2 * 65536);
		auto s3 = static_cast<signed short>(v3 * 65536);
		auto s4 = static_cast<signed short>(v4 * 65536);
		
		_packed ^= _packed;
		WRITEBITS(BitCast<unsigned short>(s1), 16);
		WRITEBITS(BitCast<unsigned short>(s2), 16);
		WRITEBITS(BitCast<unsigned short>(s3), 16);
		WRITEBITS(BitCast<unsigned short>(s4), 0);
	}
}