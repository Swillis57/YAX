#ifndef _NORMALIZED_SHORT_2_H
#define _NORMALIZED_SHORT_2_H

#include "IPackedVector.h"

namespace XNA
{
	struct NormalizedShort2 : IPackedVector<ui32>
	{
		NormalizedShort2(float, float);
		NormalizedShort2(const Vector2&);
		~NormalizedShort2();

		ui32 PackedValue() override;
		void PackedValue(ui32) override;

		Vector2 ToVector2();
		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const NormalizedShort2&, const NormalizedShort2&);
		friend bool operator!=(const NormalizedShort2&, const NormalizedShort2&);
	};
}

#endif