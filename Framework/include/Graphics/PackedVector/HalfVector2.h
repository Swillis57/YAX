#ifndef _HALF_VECTOR_2_H
#define _HALF_VECTOR_2_H

#include "IPackedVector.h"

namespace XNA
{
	struct HalfVector2 : IPackedVector<ui32>
	{
		HalfVector2(float, float);
		HalfVector2(const Vector2&);
		~HalfVector2();

		ui32 PackedValue() override;
		void PackedValue(ui32) override;

		Vector2 ToVector2();
		void PackFromVector4(const Vector4&) override;
		Vector4 ToVector4() override;
		
		friend bool operator==(const HalfVector2&, const HalfVector2&);
		friend bool operator!=(const HalfVector2&, const HalfVector2&);
	};
}

#endif