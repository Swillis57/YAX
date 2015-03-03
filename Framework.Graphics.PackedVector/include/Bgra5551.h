#ifndef _BGRA5551_H
#define _BGRA5551_H

#include "IPackedVector.h"

namespace YAX
{
	/**
	* Stores 4 unsigned normalized values between 0 and 1, using 5 bits each for 
	* blue, green, and red and 1 bit for alpha. Any value but 0 given for alpha will be
	* stored as 1.0.
	*/
	struct Bgra5551 : public IPackedVector<ui16>
	{						 
		typedef IPackedVector<ui16> Base;

		/**
		* @param b,g,r,a The values to pack
		*/
		Bgra5551(float b, float g, float r, float a);
		
		/**
		* @param vec The vector to pack values from, assumed to be in BGRA order
		*/
		Bgra5551(const Vector4& vec);
		~Bgra5551();

		/**
		* Unpacks values into a Vector4
		* 
		* @return Vector4 containing the unpacked values in BGRA order
		*/
		Vector4 ToVector4() const override;

		/**
		* @param vec The vector to pack values from, assumed to be in BGRA order 
		*/
		void PackFromVector4(const Vector4& vec) override;

		friend bool operator==(const Bgra5551&, const Bgra5551&);
		friend bool operator!=(const Bgra5551&, const Bgra5551&);

	private:
		void Pack(float b, float g, float r, float a);
	};
}


#endif