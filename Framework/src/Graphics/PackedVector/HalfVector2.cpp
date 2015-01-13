#include "../../../include/Graphics/PackedVector/HalfVector2.h"
#include "../../../include/Graphics/PackedVector/HalfSingle.h"
#include "../../../include/Math/Vector2.h"
#include "../../../include/Math/Vector4.h"

namespace YAX
{

	HalfVector2::HalfVector2(float val1, float val2)
		: HalfVector2::Base()
	{
		Pack(val1, val2);
	}

	HalfVector2::HalfVector2(const Vector2& source)
		: HalfVector2(source.X(), source.Y())
	{}

	HalfVector2::~HalfVector2() = default;

	Vector2 HalfVector2::ToVector2() const
	{
		return Vector2
		(
			HalfSingle::Unpack(READBITS(0xFFFF, 16)),
			HalfSingle::Unpack(READBITS(0xFFFF, 0))
		);
	}

	void HalfVector2::PackFromVector4(const Vector4& source)
	{
		Pack(source.X(), source.Y());
	}

	Vector4 HalfVector2::ToVector4() const
	{
		return Vector4(ToVector2(), 0, 1.0f);
	}

	bool operator==(const HalfVector2& lhs, const HalfVector2& rhs)
	{
		return lhs._packed == rhs._packed;
	}

	bool operator!=(const HalfVector2& lhs, const HalfVector2& rhs)
	{
		return !(lhs == rhs);
	}

	void HalfVector2::Pack(float val1, float val2)
	{
		_packed ^= _packed;
		WRITEBITS(HalfSingle::Pack(val1), 16);
		WRITEBITS(HalfSingle::Pack(val2), 0);
	}
}