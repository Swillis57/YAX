#include "../include/NormalizedByte4.h"
#include "../../Framework.Math/include/Vector4.h"


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
			BitCast<float>(val1),
			BitCast<float>(val2),
			BitCast<float>(val3),
			BitCast<float>(val4)
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
		signed char val1Fixed = val1 * 255;
		signed char val2Fixed = val2 * 255;
		signed char val3Fixed = val3 * 255;
		signed char val4Fixed = val4 * 255;
		
		_packed ^= _packed;
		WRITEBITS(BitCast<byte>(val1Fixed), 8);
		WRITEBITS(BitCast<byte>(val2Fixed), 8);
		WRITEBITS(BitCast<byte>(val3Fixed), 8);
		WRITEBITS(BitCast<byte>(val4Fixed), 0);
	}
}