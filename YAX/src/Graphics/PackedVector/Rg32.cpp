#include "../../../include/Graphics/PackedVector/Rg32.h"
#include "../../../include/MathHelper.h"
#include "../../../include/Vector2.h"
#include "../../../include/Vector4.h"

namespace YAX
{
    const SurfaceFormat Rg32::Format = SurfaceFormat::Rg32;

    Rg32::Rg32(float r, float g)
        : Base()
    {
        Pack(r, g);
    }

    Rg32::Rg32(const Vector2& v)
        : Rg32(v.X, v.Y)
    {}

    Rg32::~Rg32() = default;

    Vector2 Rg32::ToVector2() const
    {
        ui16 r = READBITS(0xFFFF, 16);
        ui16 g = READBITS(0xFFFF, 0);

        return Vector2
        (
            r / 65536.0f,
            g / 65536.0f
        );
    }

    Vector4 Rg32::ToVector4() const
    {
        return Vector4(ToVector2(), 0.0f, 1.0f);
    }

    void Rg32::PackFromVector4(const Vector4& v)
    {
        Pack(v.X, v.Y);
    }

    void Rg32::Pack(float r, float g)
    {
        using MathHelper::Clamp;

        ui16 rBits = static_cast<ui16>(Clamp(r, 0, 1) * 65536);
        ui16 gBits = static_cast<ui16>(Clamp(g, 0, 1) * 65536);

        WRITEBITS(rBits, 16);
        WRITEBITS(gBits, 0);
    }

    bool operator==(const Rg32& lhs, const Rg32& rhs)
    {
        return lhs._packed == rhs._packed;
    }

    bool operator!=(const Rg32& lhs, const Rg32& rhs)
    {
        return !(lhs == rhs);
    }
}