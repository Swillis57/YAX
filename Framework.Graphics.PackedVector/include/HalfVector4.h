#ifndef _HALF_VECTOR_4_H
#define _HALF_VECTOR_4_H


#include "IPackedVector.h"

namespace YAX
{
	/**
	* Stores 4 HalfSingle types contiguously
	*/
	struct HalfVector4 : public IPackedVector<ui64>
	{
		typedef IPackedVector<ui64> Base;

		/**
		* @param val1,val2,val3,val4 The values to pack
		*/
		HalfVector4(float val1, float val2, float val3, float val4);
		
		/**
		* @param vec The vector to pack values from
		*/
		HalfVector4(const Vector4& vec);
		~HalfVector4();

		/**
		* @return A Vector4 with its components set to the unpacked values
		*/
		Vector4 ToVector4() const override;

		/**
		* @param vec The vector to pack values from
		*/
		void PackFromVector4(const Vector4& vec) override;

		friend bool operator==(const HalfVector4&, const HalfVector4&);
		friend bool operator!=(const HalfVector4&, const HalfVector4&);
		
	private:
		void Pack(float, float, float, float);
	};
}

#endif