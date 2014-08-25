#ifndef SHORT_2
#define SHORT_2

#include "IPackedVector.h"

namespace XNA
{
	struct Short2 : IPackedVector<ui32>
	{
		Short2(float, float);
		Short2(const Vector2&);
		~Short2();

		ui32 PackedValue() override;
		void PackedValue(ui32) override;

		Vector2 ToVector2();
		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Short2&, const Short2&);
		friend bool operator!=(const Short2&, const Short2&);
	};
}

#endif