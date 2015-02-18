#ifndef _NORMALIZED_BYTE_2_H
#define _NORMALIZED_BYTE_2_H

#include "IPackedVector.h"

namespace YAX
{
	struct NormalizedByte2 : IPackedVector<ui16>
	{
		typedef IPackedVector<ui16> Base;

		NormalizedByte2(float val1, float val2);
		NormalizedByte2(const Vector2&);
		~NormalizedByte2();

		Vector2 ToVector2() const;
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const NormalizedByte2&, const NormalizedByte2&);
		friend bool operator!=(const NormalizedByte2&, const NormalizedByte2&);
		
	private:
		void Pack(float, float);
	};
}


#endif