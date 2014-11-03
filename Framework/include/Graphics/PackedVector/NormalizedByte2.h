#ifndef _NORMALIZED_BYTE_2_H
#define _NORMALIZED_BYTE_2_H

#include "IPackedVector.h"

namespace XNA
{
	struct NormalizedByte2 : IPackedVector<ui16>
	{
		NormalizedByte2(float, float);
		NormalizedByte2(const Vector2&);

		ui16 PackedValue() const override;
		void PackedValue(ui16) override;

		Vector2 ToVector2() const;
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const NormalizedByte2&, const NormalizedByte2&);
		friend bool operator!=(const NormalizedByte2&, const NormalizedByte2&);
	};
}


#endif