#ifndef _BYTE_4_H
#define _BYTE_4_H

#include "IPackedVector.h"

namespace YAX
{
	/**
	* Stores 4 unsigned integers between 0 and 255 using 8 bits for each
	*/
	struct Byte4 : public IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		/**
		* @param r,b,g,a The components to be packed 
		*/
		Byte4(float r, float g, float b, float a);
		
		/**
		* @param vec The vector to pack values from
		*/
		Byte4(const Vector4& vec);
		~Byte4();

		/**
		* @return Vector4 containing the unpacked values
		*/
		Vector4 ToVector4() const override;

		/**
		* @param vec The vector to pack values from 
		*/
		void PackFromVector4(const Vector4& vec) override;

		friend bool operator==(const Byte4&, const Byte4&);
		friend bool operator!=(const Byte4&, const Byte4&);

	private:
		void Pack(float, float, float, float);
	};
}

#endif