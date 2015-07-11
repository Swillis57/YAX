#ifndef _NORMALIZED_SHORT_4_H
#define _NORMALIZED_SHORT_4_H

#include "IPackedVector.h"

namespace YAX
{
    /**
    * Stores 4 16-bit signed normalized values between -1 and 1
    */
    struct NormalizedShort4 : public IPackedVector<ui64>
    {
        typedef IPackedVector<ui64> Base;

        /**
        * @param val1,val2,val3,val4 The values to pack
        */
        NormalizedShort4(float val1, float val2, float vec3, float vec4);
        
        /**
        * @param vec The vector to pack values from
        */
        NormalizedShort4(const Vector4& vec);

        ~NormalizedShort4();

        /**
        * @return A Vector4 with the components set to the unpacked values
        */
        Vector4 ToVector4() const override;

        /**
        * @param vec The vector to retrieve values from
        */
        void PackFromVector4(const Vector4& vec) override;

        friend bool operator==(const NormalizedShort4&, const NormalizedShort4&);
        friend bool operator!=(const NormalizedShort4&, const NormalizedShort4&);
    
    private:
        void Pack(float, float, float, float);
    };
}

#endif

