#ifndef _RGBA_64_H
#define _RGBA_64_H

#include "IPackedVector.h"

namespace YAX
{
    struct Rgba64 : public IPackedVector<ui64>
    {
        typedef IPackedVector<ui64> Base;
        static const SurfaceFormat Format;

        Rgba64(float r, float g, float b, float a);
        Rgba64(const Vector4&);
        ~Rgba64();

        Vector4 ToVector4() const override;
        void PackFromVector4(const Vector4&) override;

        friend bool operator==(const Rgba64&, const Rgba64&);
        friend bool operator!=(const Rgba64&, const Rgba64&);
    
    private:
        void Pack(float, float, float, float);
    };
}

#endif

