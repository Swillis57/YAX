#ifndef _BGRA5551_H
#define _BGRA5551_H

#include "IPackedVector.h"

namespace XNA
{
	struct Bgra5551 : IPackedVector<ui16>
	{
		Bgra5551(float, float, float, float);
		Bgra5551(const Vector4&);
		~Bgra5551();

		ui16 PackedValue() override;
		void PackedValue(ui16) override;

		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Bgra5551&, const Bgra5551&);
		friend bool operator!=(const Bgra5551&, const Bgra5551&);
	};
}


#endif