#ifndef _NORMALIZED_SHORT_2_H
#define _NORMALIZED_SHORT_2_H

#include "IPackedVector.h"

namespace YAX
{
	/**
	* Stores 2 16-bit signed normalized values between -1 and 1
	*/
	struct NormalizedShort2 : public IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		/**
		* @param val1,val2 The values to pack
		*/
		NormalizedShort2(float val1, float val2);

		/**
		* @param vec The vector to pack values from
		*/
		NormalizedShort2(const Vector2& vec);
		~NormalizedShort2();

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

		friend bool operator==(const NormalizedShort2&, const NormalizedShort2&);
		friend bool operator!=(const NormalizedShort2&, const NormalizedShort2&);
	
	private:
		void Pack(float, float);
	};
}

#endif