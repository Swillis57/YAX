#include "../../../include/Graphics/PackedVector/HalfSingle.h"
#include "../../../include/Math/Vector4.h"

namespace YAX
{
	HalfSingle::HalfSingle(float val)
		: HalfSingle::Base()
	{
		Pack(val);
	}

	HalfSingle::~HalfSingle() = default;

	float HalfSingle::ToSingle() const
	{
		ui32 res = 0;
		res |= READBITS(0x1, 15);
		res <<= 1;
		res |= READBITS(0x1, 14);
		res <<= 7;
		res |= READBITS(0xF, 10);
		res <<= 10;
		res |= READBITS(0x3FF, 0);
		res <<= 13;

		return *(float*)&res;
	}

	void HalfSingle::PackFromVector4(const Vector4& source)
	{
		Pack(source.X());
	}

	Vector4 HalfSingle::ToVector4() const
	{
		return Vector4(ToSingle(), 0, 0, 1.0f);
	}

	bool operator==(const HalfSingle& lhs, const HalfSingle& rhs)
	{
		return lhs._packed == rhs._packed;
	}
	
	bool operator!=(const HalfSingle& lhs, const HalfSingle& rhs)
	{
		return !(lhs == rhs);
	}

	void HalfSingle::Pack(float val)
	{
		ui32 bits = *(ui32*)&val;
		byte sign = bits & (1 << 31);
		byte expoSign = bits & (1 << 30);
		byte expo = bits & (0xF << 22);
		ui16 mantissa = bits & (0x3FF << 12);

		_packed ^= _packed;
		WRITEBITS(sign, 1);
		WRITEBITS(expoSign, 4);
		WRITEBITS(expo, 10);
		WRITEBITS(mantissa, 0);
	}
}