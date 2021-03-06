#include "Graphics/PackedVector/Bgr565.h"
#include "MathHelper.h"
#include "Vector3.h"
#include "Vector4.h"

namespace YAX
{
    const SurfaceFormat Bgr565::Format = SurfaceFormat::Bgr565;

    Bgr565::Bgr565(float b, float g, float r)
        : Base()
    {
        Pack(b, g, r);
    }

    Bgr565::Bgr565(const Vector3& source)
        : Bgr565(source.X, source.Y, source.Z)
    {}

    Bgr565::~Bgr565() = default;

    Vector3 Bgr565::ToVector3() const
    {
        return Vector3
        (
            READBITS(0x1F, 11) / 31.0f,
            READBITS(0x3F, 5) / 63.0f,
            READBITS(0x1F, 0) / 31.0f
        );
    }

    Vector4 Bgr565::ToVector4() const
    {
        return Vector4(ToVector3(), 1.0f);
    }

    void Bgr565::PackFromVector4(const Vector4& source)
    {
        Pack(source.Z, source.Y, source.X);
    }

    bool operator==(const Bgr565& lhs, const Bgr565& rhs)
    {
        return (lhs._packed == rhs._packed);
    }

    bool operator!=(const Bgr565& lhs, const Bgr565& rhs)
    {
        return !(lhs == rhs);
    }

    void Bgr565::Pack(float b, float g, float r)
    {
        using MathHelper::Clamp;

        byte redBits =   static_cast<byte>(Clamp(r, 0, 1) * 31);
        byte greenBits = static_cast<byte>(Clamp(g, 0, 1) * 63);
        byte blueBits =  static_cast<byte>(Clamp(b, 0, 1) * 31);

        _packed ^= _packed;
        WRITEBITS(blueBits, 6)
        WRITEBITS(greenBits, 5)
        WRITEBITS(redBits, 0);
    }
    
}