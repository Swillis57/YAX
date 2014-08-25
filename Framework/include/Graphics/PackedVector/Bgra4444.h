#ifndef BGRA4444
#define BGRA4444

#include "IPackedVector.h"

namespace XNA
{
	struct Bgra4444 : IPackedVector<ui16>
	{
		Bgra4444(float, float, float, float);
		Bgra4444(const Vector4&);
		~Bgra4444();

		ui16 PackedValue() override;
		void PackedValue(ui16) override;

		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Bgra4444&, const Bgra4444&);
		friend bool operator!=(const Bgra4444&, const Bgra4444&);
	};
}


#endif