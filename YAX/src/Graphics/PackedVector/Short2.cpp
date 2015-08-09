#include "Graphics/PackedVector/Short2.h"
#include "Vector2.h"
#include "Vector4.h"

namespace YAX
{
    Short2::Short2(float s1, float s2)
        : Base()
    {
        Pack(s1, s2);
    }

    Short2::Short2(const Vector2& v)
        : Short2(v.X, v.Y)
    {}

    Short2::~Short2() = default;

    Vector2 Short2::ToVector2() const
    {
        ui16 s1Bits = READBITS(0xFFFF, 16);
        ui16 s2Bits = READBITS(0xFFFF, 0);

        return Vector2
        (
            BitCast<i16>(s1Bits),
            BitCast<i16>(s2Bits)		
        );
    }

    Vector4 Short2::ToVector4() const
    {
        return Vector4(ToVector2(), 0, 1.0f);
    }

    void Short2::PackFromVector4(const Vector4& v)
    {
        Pack(v.X, v.Y);
    }

    void Short2::Pack(float s1, float s2)
    {
        i16 s1Fixed = static_cast<i16>(s1);
        i16 s2Fixed = static_cast<i16>(s2);

        WRITEBITS(s1Fixed, 16);
        WRITEBITS(s2Fixed, 0);
    }

    bool operator==(const Short2& lhs, const Short2& rhs)
    {
        return lhs._packed == rhs._packed;
    }

    bool operator!=(const Short2& lhs, const Short2& rhs)
    {
        return !(lhs == rhs);
    }
}