#ifndef _RGBA_10_10_10_2_H
#define _RGBA_10_10_10_2_H

#include "IPackedVector.h"

namespace YAX
{
	struct Rgba1010102 : IPackedVector<ui32>
	{
		Rgba1010102(float, float);
		Rgba1010102(const Vector2&);

		ui32 PackedValue() const override;
		void PackedValue(ui32) override;

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Rgba1010102&, const Rgba1010102&);
		friend bool operator!=(const Rgba1010102&, const Rgba1010102&);
	};
}

#endif