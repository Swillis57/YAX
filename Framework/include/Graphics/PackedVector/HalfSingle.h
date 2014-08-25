#ifndef HALF_SINGLE
#define HALF_SINGLE

#include "IPackedVector.h"

namespace XNA
{
	struct HalfSingle : IPackedVector<ui16>
	{
		HalfSingle(float);
		~HalfSingle();

		ui16 PackedValue() override;
		void PackedValue(ui16) override;

		float ToSingle();
		void PackFromVector4(const Vector4&) override;
		Vector4 ToVector4() override;

		friend bool operator==(const HalfSingle&, const HalfSingle&);
		friend bool operator!=(const HalfSingle&, const HalfSingle&);
	};
}

#endif