#include "../../../include/Graphics/PackedVector/Rgba1010102.h"
#include "../../../include/MathHelper.h"
#include "../../../include/Vector4.h"

namespace YAX
{
    const SurfaceFormat Rgba1010102::Format = SurfaceFormat::Rgba1010102;

    Rgba1010102::Rgba1010102(float r, float g, float b, float a)
        : Base()
    {
        Pack(r, g, b, a);
    }

    Rgba1010102::Rgba1010102(const Vector4& v)
        : Rgba1010102(v.X, v.Y, v.Z, v.W)
    {}

    Rgba1010102::~Rgba1010102() = default;

    Vector4 Rgba1010102::ToVector4() const
    {
        ui16 r = READBITS(0x3FF, 22);
        ui16 b = READBITS(0x3FF, 12);
        ui16 g = READBITS(0x3FF, 2);
        ui16 a = READBITS(0x3, 0);

        return Vector4
        (
            r / 1024.0f,
            g / 1024.0f,
            b / 1024.0f,
            a / 4.0f
        );
    }

    void Rgba1010102::PackFromVector4(const Vector4& v)
    {
        Pack(v.X, v.Y, v.Z, v.W);
    }

    void Rgba1010102::Pack(float r, float g, float b, float a)
    {
        using MathHelper::Clamp;

        ui16 rBits = static_cast<ui16>(Clamp(r, 0, 1) * 1024);
        ui16 gBits = static_cast<ui16>(Clamp(g, 0, 1) * 1024);
        ui16 bBits = static_cast<ui16>(Clamp(b, 0, 1) * 1024);
        ui16 aBits = static_cast<ui16>(Clamp(a, 0, 1) * 1024);

        WRITEBITS(rBits, 10);
        WRITEBITS(gBits, 10);
        WRITEBITS(bBits, 2);
        WRITEBITS(aBits, 0);
    }

    bool operator==(const Rgba1010102& lhs, const Rgba1010102& rhs)
    {
        return lhs._packed == rhs._packed;
    }

    bool operator!=(const Rgba1010102& lhs, const Rgba1010102& rhs)
    {
        return !(lhs == rhs);
    }
}