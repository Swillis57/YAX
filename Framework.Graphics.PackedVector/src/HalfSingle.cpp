#include "../include/HalfSingle.h"
#include "../../Framework.Math/include/Vector4.h"

namespace YAX
{
	ui16 HalfSingle::Pack(float val)
	{
		ui16 res;
		
		ui32 bits = BitCast<ui32>(val);
		byte sign = bits & (1 << 31);
		byte expoSign = bits & (1 << 30);
		byte expo = bits & (0xF << 22);
		ui16 mantissa = bits & (0x3FF << 12);

		res ^= res;
		WRITEBITS_STATIC(res, sign, 1);
		WRITEBITS_STATIC(res, expoSign, 4);
		WRITEBITS_STATIC(res, expo, 10);
		WRITEBITS_STATIC(res, mantissa, 0);

		return res;
	}

	float HalfSingle::Unpack(ui16 source)
	{
		ui32 res = 0;
		res |= READBITS_STATIC(source, 0x1, 15);
		res <<= 1;
		res |= READBITS_STATIC(source, 0x1, 14);
		res <<= 7;
		res |= READBITS_STATIC(source, 0xF, 10);
		res <<= 10;
		res |= READBITS_STATIC(source, 0x3FF, 0);
		res <<= 13;

		return *(float*)&res;
	}
	  
	HalfSingle::HalfSingle(float val)
		: HalfSingle::Base()
	{
		_packed = Pack(val);
	}

	HalfSingle::~HalfSingle() = default;

	float HalfSingle::ToSingle() const
	{
		return Unpack(_packed);
	}

	void HalfSingle::PackFromVector4(const Vector4& source)
	{
		_packed = Pack(source.X);
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
}