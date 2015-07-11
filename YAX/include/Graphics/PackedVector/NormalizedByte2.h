#ifndef _NORMALIZED_BYTE_2_H
#define _NORMALIZED_BYTE_2_H

#include "IPackedVector.h"

namespace YAX
{
    /**
    * Stores two 8-bit signed normalized values between -1 and 1
    */
    struct NormalizedByte2 : public IPackedVector<ui16>
    {
        typedef IPackedVector<ui16> Base;
        static const SurfaceFormat Format;

        /**
        * @param val1,val2 The values to pack
        */
        NormalizedByte2(float val1, float val2);

        /**
        * @param vec The vector to pack values from
        */
        NormalizedByte2(const Vector2& vec);
        ~NormalizedByte2();

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
        * @param vec The vector to pack values from  
        */
        void PackFromVector4(const Vector4& vec) override;

        friend bool operator==(const NormalizedByte2&, const NormalizedByte2&);
        friend bool operator!=(const NormalizedByte2&, const NormalizedByte2&);
        
    private:
        void Pack(float, float);
    };
}


#endif