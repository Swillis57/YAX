#include "Graphics/PackedVector/NormalizedByte2.h"
#include "MathHelper.h"
#include "Vector2.h"
#include "Vector4.h"

namespace YAX
{
    const SurfaceFormat NormalizedByte2::Format = SurfaceFormat::NormalizedByte2;

    NormalizedByte2::NormalizedByte2(float val1, float val2)
        : Base()
    {
        Pack(val1, val2);
    }

    NormalizedByte2::NormalizedByte2(const Vector2& source)
        : NormalizedByte2(source.X, source.Y)
    {}

    NormalizedByte2::~NormalizedByte2() = default;

    Vector2 NormalizedByte2::ToVector2() const
    {
        byte val1 = READBITS(0xFF, 8);
        byte val2 = READBITS(0xFF, 0);

        return Vector2
        (
            BitCast<signed char>(val1) / 128.0f,
            BitCast<signed char>(val2) / 128.0f
        );
    }

    Vector4 NormalizedByte2::ToVector4() const
    {
        return Vector4(ToVector2(), 0.0f, 1.0f);
    }

    void NormalizedByte2::PackFromVector4(const Vector4& source)
    {
        Pack(source.X, source.Y);
    }

    bool operator==(const NormalizedByte2& lhs, const NormalizedByte2& rhs)
    {
        return lhs._packed == rhs._packed;
    }

    bool operator!=(const NormalizedByte2& lhs, const NormalizedByte2& rhs)
    {
        return !(lhs == rhs);
    }

    void NormalizedByte2::Pack(float val1, float val2)
    {
        using MathHelper::Clamp;

        auto val1Fixed = static_cast<signed char>(Clamp(val1, -1, 1) * 128);
        auto val2Fixed = static_cast<signed char>(Clamp(val2, -1, 1) * 128);

        _packed ^= _packed;
        WRITEBITS(val1Fixed, 8);
        WRITEBITS(val2Fixed, 0);
    }
}