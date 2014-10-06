#ifndef _HALF_VECTOR_4_H
#define _HALF_VECTOR_4_H

#include "IPackedVector.h"

namespace XNA
{
	struct HalfVector4 : IPackedVector<ui64>
	{
		HalfVector4(float, float, float, float);
		HalfVector4(const Vector4&);
		~HalfVector4();

		ui64 PackedValue() override;
		void PackedValue(ui64) override;

		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const HalfVector4&, const HalfVector4&);
		friend bool operator!=(const HalfVector4&, const HalfVector4&);
	};
}

#endif