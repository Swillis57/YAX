#ifndef _HALF_SINGLE_H
#define _HALF_SINGLE_H

#include "IPackedVector.h"

namespace YAX
{
    /**
    * Stores a single 16-bit float
    */
    struct HalfSingle : public IPackedVector<ui16>
    {
        typedef IPackedVector<ui16> Base;
        static const SurfaceFormat Format;

        /**
        * Packs a 32-bit float into a 16-bit float
        *
        * @param f The float to pack
        */
        static ui16 Pack(float f);

        /**
        * Unpacks a 16-bit float from an unsigned short
        *
        * @param u The unsigned short containing the bits of the float
        * @return The unpacked float
        */
        static float Unpack(ui16 u);

        /**
        * @param val The value to pack
        */
        HalfSingle(float val);
        ~HalfSingle();

        /**
        * Unpacks the stored 16-bit value into a 32-bit float
        *
        * @return The unpacked value
        */
        float ToSingle() const;

        /**
        * Packs the first (X) component of a vector into a 16-bit float
        *
        * @param vec The vector to retrieve the value from
        */
        void PackFromVector4(const Vector4& vec) override;

        /**
        * @return A vector whose X component is set to the unpacked value
        */
        Vector4 ToVector4() const override;

        friend bool operator==(const HalfSingle&, const HalfSingle&);
        friend bool operator!=(const HalfSingle&, const HalfSingle&);
    };
}

#endif