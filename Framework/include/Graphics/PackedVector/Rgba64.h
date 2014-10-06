#ifndef _RGBA_64_H
#define _RGBA_64_H

#include "IPackedVector.h"

namespace XNA
{
	struct Rgba64 : IPackedVector<ui64>
	{
		Rgba64(float, float, float, float);
		Rgba64(const Vector4&);
		~Rgba64();

		ui64 PackedValue() override;
		void PackedValue(ui64) override;


		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Rgba64&, const Rgba64&);
		friend bool operator!=(const Rgba64&, const Rgba64&);
	};
}

#endif

