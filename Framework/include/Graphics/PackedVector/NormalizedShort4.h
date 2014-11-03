#ifndef _NORMALIZED_SHORT_4_H
#define _NORMALIZED_SHORT_4_H

#include "IPackedVector.h"

namespace XNA
{
	struct NormalizedShort4 : IPackedVector<ui64>
	{
		NormalizedShort4(float, float, float, float);
		NormalizedShort4(const Vector4&);

		ui64 PackedValue() const override;
		void PackedValue(ui64) override;


		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const NormalizedShort4&, const NormalizedShort4&);
		friend bool operator!=(const NormalizedShort4&, const NormalizedShort4&);
	};
}

#endif

