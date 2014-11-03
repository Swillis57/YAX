#ifndef _HALF_VECTOR_2_H
#define _HALF_VECTOR_2_H

#include "IPackedVector.h"

namespace XNA
{
	struct HalfVector2 : IPackedVector<ui32>
	{
		HalfVector2(float, float);
		HalfVector2(const Vector2&);

		ui32 PackedValue() const override;
		void PackedValue(ui32) override;

		Vector2 ToVector2() const;
		void PackFromVector4(const Vector4&) override;
		Vector4 ToVector4() const override;
		
		friend bool operator==(const HalfVector2&, const HalfVector2&);
		friend bool operator!=(const HalfVector2&, const HalfVector2&);
	};
}

#endif