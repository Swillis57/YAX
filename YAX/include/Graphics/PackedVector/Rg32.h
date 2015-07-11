#ifndef _RG_32_H
#define _RG_32_H

#include "IPackedVector.h"

namespace YAX
{
    /**
    * Stores two 16-bit unsigned normalized values between 0 and 1
    */
    struct Rg32 : public IPackedVector<ui32>
    {
        typedef IPackedVector<ui32> Base;
        static const SurfaceFormat Format;

        /**
        * @param r,g The values to pack
        */
        Rg32(float r, float g);

        /**
        * @param vec The vector to retrieve values from
        */
        Rg32(const Vector2& vec);
        ~Rg32();

        /**
        * @return A Vector2 with the components set to the unpacked values
        */
        Vector2 ToVector2() const;

        /**
        * @return A Vector4 with the X and Y components set to the unpacked values
        */
        Vector4 ToVector4() const override;

        /**
        * Packs the X and Y components of a given vector
        *
        * @param vec The vector to retrieve values from
        */
        void PackFromVector4(const Vector4& vec) override;

        friend bool operator==(const Rg32&, const Rg32&);
        friend bool operator!=(const Rg32&, const Rg32&);

    private:
        void Pack(float, float);
    };
}

#endif