#ifndef _ALPHA8_H
#define _ALPHA8_H

#include "IPackedVector.h"

namespace YAX
{	
    /**
    * Stores an 8 bit normalized value in the range of 0 to 1
    */
    struct Alpha8 : public IPackedVector<byte>
    {
        typedef IPackedVector<byte> Base;
        static const SurfaceFormat Format;

        /**
        * @param val The value between 0 and 1 to pack
        */
        Alpha8(float val);
        ~Alpha8();

        /**
        * Unpack the floating point value
        * 
        * @return The original unpacked value
        */
        float ToAlpha() const;

        /**
        * Packs the W component of a Vector4
        *
        * @param source The vector to get the value to pack from
        */
        void PackFromVector4(const Vector4& source) override;

        /**
        * Unpacks the stored value into the W component of a Vector4
        *
        * @return Vector4 with the W component set to the unpacked value
        */
        Vector4 ToVector4() const override;
        
        friend bool operator==(const Alpha8&, const Alpha8&);
        friend bool operator!=(const Alpha8&, const Alpha8&);

    };

    
    
}


#endif