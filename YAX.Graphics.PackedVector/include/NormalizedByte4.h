#ifndef _NORMALIZED_BYTE_4_H
#define _NORMALIZED_BYTE_4_H

#include "IPackedVector.h"

namespace YAX
{
	/**
	* Stores 4 8-bit signed normalized values between -1 and 1 
	*/
	struct NormalizedByte4 : public IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		/**
		* @param val1,val2,val3,val4 The values to pack
		*/
		NormalizedByte4(float val1, float val2, float val3, float val4);
		
		/**
		* @param vec The vector to retrieve values from
		*/
		NormalizedByte4(const Vector4& vec);
		~NormalizedByte4();
		
		/**
		* @return Vector4 with the components set to the unpacked values
		*/
		Vector4 ToVector4() const override;

		/**
		* @param vec The vector to pack values from 
		*/
		void PackFromVector4(const Vector4& vec) override;

		friend bool operator==(const NormalizedByte4&, const NormalizedByte4&);
		friend bool operator!=(const NormalizedByte4&, const NormalizedByte4&);
		
	private:
		void Pack(float, float, float, float);
	};
}

#endif

