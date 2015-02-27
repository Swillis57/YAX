#ifndef _BGRA4444_H
#define _BGRA4444_H

#include "IPackedVector.h"

namespace YAX
{
	/**
	* Stores four unsigned normalized values between 0 and 1,
	* with each value using 4 bits
	*/
	struct Bgra4444 : public IPackedVector<ui16>
	{
		typedef IPackedVector<ui16> Base;

		/**
		* @param b,g,r,a the values to pack
		*/
		Bgra4444(float b, float g, float r, float a);

		/**
		* @param vec The vector containing the values to pack
		*/
		Bgra4444(const Vector4& vec);
		~Bgra4444();

		/**
		* Unpacks the values into a Vector4
		*
		* @return A Vector4 with X = blue, Y = green, Z = red, W = alpha
		*/
		Vector4 ToVector4() const override;

		/**
		* Packs the values of a Vector4
		* 
		* @param vec The vector to retrieve the values from
		*/
		void PackFromVector4(const Vector4& vec) override;

		friend bool operator==(const Bgra4444&, const Bgra4444&);
		friend bool operator!=(const Bgra4444&, const Bgra4444&);  

	private:
		void Pack(float b, float g, float r, float a);
	};
}


#endif