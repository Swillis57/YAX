#ifndef _RGBA_64_H
#define _RGBA_64_H

#include "IPackedVector.h"

namespace YAX
{
	struct Rgba64 : IPackedVector<ui64>
	{
		Rgba64(float, float, float, float);
		Rgba64(const Vector4&);

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Rgba64&, const Rgba64&);
		friend bool operator!=(const Rgba64&, const Rgba64&);
	};
}

#endif

