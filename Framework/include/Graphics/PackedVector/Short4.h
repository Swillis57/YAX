#ifndef _SHORT_4_H
#define _SHORT_4_H

#include "IPackedVector.h"

namespace YAX
{
	struct Short4 : IPackedVector<ui64>
	{
		Short4(float, float, float, float);
		Short4(const Vector4&);

		ui64 PackedValue() const override;
		void PackedValue(ui64) override;


		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Short4&, const Short4&);
		friend bool operator!=(const Short4&, const Short4&);
	};
}

#endif

