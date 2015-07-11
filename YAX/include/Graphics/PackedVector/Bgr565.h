#ifndef _BGR_5_6_5_H
#define _BGR_5_6_5_H

#include "IPackedVector.h"


namespace YAX
{
    /**
    * Stores three unsigned nomalized values between 0 and 1.
    * The blue and red components use 5 bits and the green uses 6 bits.
    */
    struct Bgr565 : public IPackedVector<ui16>
    {
        typedef IPackedVector<ui16> Base;
        static const SurfaceFormat Format;

        /**
        * @param b,g,r Unsigned floating point numbers between 0 and 1
        */
        Bgr565(float b, float g, float r);

        /**
        * @param vec The vector to pull values from
        */
        Bgr565(const Vector3& vec);
        ~Bgr565();

        /**
        * Unpacks the three stored values into a Vector3
        *
        * @return A Vector3 with X = blue, Y = green, and Z = red
        */
        Vector3 ToVector3() const;

        /**
        * Unpacks the three stored values into a Vector4
        *
        * @return A Vector4 with X = blue, Y = green, Z = red, and W = 1.0f
        */
        Vector4 ToVector4() const override;

        /**
        * Packs the first three components of a Vector4
        *
        * @param vec The vector to retrieve values from
        */
        void PackFromVector4(const Vector4& vec) override;
        
        friend bool operator==(const Bgr565&, const Bgr565&);
        friend bool operator!=(const Bgr565&, const Bgr565&);

    private:
        void Pack(float b, float g, float r);

    };
}


#endif