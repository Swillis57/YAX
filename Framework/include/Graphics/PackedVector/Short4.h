#ifndef SHORT_4
#define SHORT_4

#include "IPackedVector.h"

namespace XNA
{
	struct Short4 : IPackedVector<ui64>
	{
		Short4(float, float, float, float);
		Short4(const Vector4&);
		~Short4();

		ui64 PackedValue() override;
		void PackedValue(ui64) override;


		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Short4&, const Short4&);
		friend bool operator!=(const Short4&, const Short4&);
	};
}

#endif

