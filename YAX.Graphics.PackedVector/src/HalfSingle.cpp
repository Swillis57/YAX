#include "../include/HalfSingle.h"
#include "../../YAX.Math/include/Vector4.h"

namespace YAX
{
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

	
	ui16 HalfSingle::Pack(float val)
	{
		ui16 res = 0;

		//Retrieve float components
		ui32 bits = BitCast<ui32>(val);
		ui32 mantissa = READBITS_STATIC(bits, 0x7FFFFF, 0);
		i32 expoBits = static_cast<i32>(READBITS_STATIC(bits, 0xFF, 23));
		byte signBit = static_cast<byte>(READBITS_STATIC(bits, 0x1, 31));
		byte expoSign = static_cast<byte>(READBITS_STATIC(expoBits, 0x1, 7));

		//Rebias exponent to 15-bit range
		expoBits -= 112;

		//If the new exponent is between1 and 30, it's a valid 16-bit expo
		//Else if it's greater than 31, return infinity
		//Else it's subnormal, so zero it out (may support this later
		if (expoBits >= 1 && expoBits <= 30)
		{
			mantissa >>= 12;
		}
		else if (expoBits >= 31)
		{
			expoSign = 1;
			expoBits = 0xFF;
			mantissa = 0;
		}
		else
		{
			expoSign = 0;
			expoBits = 0;
			mantissa = 0;
		}

		WRITEBITS_STATIC(res, signBit, 1);
		WRITEBITS_STATIC(res, expoSign, 4);
		WRITEBITS_STATIC(res, (expoBits & 0xF), 10);
		WRITEBITS_STATIC(res, mantissa, 0);

		return res;
	}

	
	float HalfSingle::Unpack(ui16 source)
	{
		ui32 res = 0;

		//Pull the bits out of the 16-bit float
		ui32 mantissa = READBITS_STATIC(source, 0x3FF, 0);
		i32 expoBits = static_cast<i32>(READBITS_STATIC(source, 0x1F, 10));
		byte signBit = static_cast<byte>(READBITS_STATIC(source, 0x1, 15));

		//Rebias into 32-bit range
		expoBits += 112;

		//Shift the mantissa to make room for 23 bits
		mantissa <<= 13;

		WRITEBITS_STATIC(res, signBit, 8);
		WRITEBITS_STATIC(res, expoBits, 23);
		WRITEBITS_STATIC(res, mantissa, 0);

		return BitCast<float>(res);
	}
}