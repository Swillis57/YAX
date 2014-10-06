#ifndef _RG_32_H
#define _RG_32_H

#include "IPackedVector.h"

namespace XNA
{
	struct Rg32 : IPackedVector<ui32>
	{
		Rg32(float, float);
		Rg32(const Vector2&);
		~Rg32();

		ui32 PackedValue() override;
		void PackedValue(ui32) override;

		Vector2 ToVector2();
		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Rg32&, const Rg32&);
		friend bool operator!=(const Rg32&, const Rg32&);
	};
}

#endif