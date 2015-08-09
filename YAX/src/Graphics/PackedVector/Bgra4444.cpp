#include "Graphics/PackedVector/Bgra4444.h"
#include "MathHelper.h"
#include "Vector4.h"

namespace YAX
{
    const SurfaceFormat Bgra4444::Format = SurfaceFormat::Bgr4444;

    Bgra4444::Bgra4444(float b, float g, float r, float a)
        : Base()
    {
        Pack(b, g, r, a);
    }

    Bgra4444::Bgra4444(const Vector4& source)
        : Bgra4444(source.X, source.Y, source.Z, source.W)
    {}

    Bgra4444::~Bgra4444() = default;

    Vector4 Bgra4444::ToVector4() const
    {
        return Vector4
        (
            READBITS(0xF, 12) / 15.0f,
            READBITS(0xF, 8) / 15.0f,
            READBITS(0xF, 4) / 15.0f,
            READBITS(0xF, 0) / 15.0f
        );
    }

    void Bgra4444::PackFromVector4(const Vector4& source)
    {
        Pack(source.X, source.Y, source.Z, source.W);
    }

    bool operator==(const Bgra4444& lhs, const Bgra4444& rhs)
    {
        return lhs._packed == rhs._packed;
    }

    bool operator!=(const Bgra4444& lhs, const Bgra4444& rhs)
    {
        return !(lhs == rhs);
    }

    void Bgra4444::Pack(float b, float g, float r, float a)
    {
        using MathHelper::Clamp;

        byte blueBits = static_cast<byte>(Clamp(b, 0, 1) * 15);
        byte greenBits = static_cast<byte>(Clamp(g, 0, 1) * 15);
        byte redBits = static_cast<byte>(Clamp(r, 0, 1) * 15);
        byte alphaBits = static_cast<byte>(Clamp(a, 0, 1) * 15);

        _packed ^= _packed;
        WRITEBITS(blueBits, 4);
        WRITEBITS(greenBits, 4);
        WRITEBITS(redBits, 4);
        WRITEBITS(alphaBits, 0);
    }

}