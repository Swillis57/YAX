#ifndef _BGRA5551_H
#define _BGRA5551_H

#include "IPackedVector.h"

namespace YAX
{
	struct Bgra5551 : IPackedVector<ui16>
	{
		Bgra5551(float, float, float, float);
		Bgra5551(const Vector4&);

		ui16 PackedValue() const override;
		void PackedValue(ui16) override;

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Bgra5551&, const Bgra5551&);
		friend bool operator!=(const Bgra5551&, const Bgra5551&);
	};
}


#endif