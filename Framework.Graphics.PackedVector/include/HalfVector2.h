#ifndef _HALF_VECTOR_2_H
#define _HALF_VECTOR_2_H

#include "IPackedVector.h"

namespace YAX
{
	/**
	* Stores two HalfSingle types contiguously
	*/
	struct HalfVector2 : public IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		/**
		* @param val1,val2 The values to pack into HalfSingles
		*/
		HalfVector2(float val1, float val2);

		/**
		* @param vec The vector to pack values from
		*/
		HalfVector2(const Vector2& vec);
		~HalfVector2();

		/**
		* @return A Vector2 whose components are the unpacked values
		*/
		Vector2 ToVector2() const;

		/**
		* Packs the X and Y components of a given Vector4 into HalfSingles
		*
		* @param vec The vector to pack values from 
		*/
		void PackFromVector4(const Vector4& vec) override;

		/**
		* @return A Vector4 with the X and Y components set to the unpacked values
		*/
		Vector4 ToVector4() const override;
		
		friend bool operator==(const HalfVector2&, const HalfVector2&);
		friend bool operator!=(const HalfVector2&, const HalfVector2&);
		
	private:
		void Pack(float, float);
	};
}

#endif