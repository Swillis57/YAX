#include "Graphics/PackedVector/HalfVector4.h"
#include "Graphics/PackedVector/HalfSingle.h"
#include "Vector4.h"

namespace YAX
{
    const SurfaceFormat HalfVector4::Format = SurfaceFormat::HalfVector4;

    HalfVector4::HalfVector4(float val1, float val2, float val3, float val4)
        : Base()
    {
        Pack(val1, val2, val3, val4);
    }

    HalfVector4::HalfVector4(const Vector4& source)
        : HalfVector4(source.X, source.Y, source.Z, source.W)
    {}

    HalfVector4::~HalfVector4() = default;

    Vector4 HalfVector4::ToVector4() const
    {
        const ui64 mask = 0xFFFF;

        return Vector4
        (
            HalfSingle::Unpack(static_cast<ui16>(READBITS(mask, 48))),
            HalfSingle::Unpack(static_cast<ui16>(READBITS(mask, 32))),
            HalfSingle::Unpack(static_cast<ui16>(READBITS(mask, 16))),
            HalfSingle::Unpack(static_cast<ui16>(READBITS(mask, 0)))
        );
    }

    void HalfVector4::PackFromVector4(const Vector4& source)
    {
        Pack(source.X, source.Y, source.Z, source.W);
    }

    bool operator==(const HalfVector4& lhs, const HalfVector4& rhs)
    {
        return lhs._packed == rhs._packed;
    }

    bool operator!=(const HalfVector4& lhs, const HalfVector4& rhs)
    {
        return !(lhs == rhs);
    }

    void HalfVector4::Pack(float val1, float val2, float val3, float val4)
    {
        WRITEBITS(HalfSingle::Pack(val1), 16);
        WRITEBITS(HalfSingle::Pack(val2), 16);
        WRITEBITS(HalfSingle::Pack(val3), 16);
        WRITEBITS(HalfSingle::Pack(val4), 0);
    }
}