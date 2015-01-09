#ifndef _BGRA4444_H
#define _BGRA4444_H

#include "IPackedVector.h"

namespace YAX
{
	struct Bgra4444 : IPackedVector<ui16>
	{
		Bgra4444(float, float, float, float);
		Bgra4444(const Vector4&);

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Bgra4444&, const Bgra4444&);
		friend bool operator!=(const Bgra4444&, const Bgra4444&);
	};
}


#endif