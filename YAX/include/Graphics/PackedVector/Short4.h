#ifndef _SHORT_4_H
#define _SHORT_4_H

#include "IPackedVector.h"

namespace YAX
{
    struct Short4 : public IPackedVector<ui64>
    {
        typedef IPackedVector<ui64> Base;

        Short4(float, float, float, float);
        Short4(const Vector4&);
        ~Short4();

        Vector4 ToVector4() const override;
        void PackFromVector4(const Vector4&) override;

        friend bool operator==(const Short4&, const Short4&);
        friend bool operator!=(const Short4&, const Short4&);
    
    private:
        void Pack(float, float, float, float);
    };
}

#endif

