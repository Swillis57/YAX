#ifndef _BYTE_4_H
#define _BYTE_4_H

#include "IPackedVector.h"

namespace YAX
{
	struct Byte4 : IPackedVector<ui32>
	{
		Byte4(float, float, float, float);
		Byte4(const Vector4&);

		ui32 PackedValue() const override;
		void PackedValue(ui32) override;

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Byte4&, const Byte4&);
		friend bool operator!=(const Byte4&, const Byte4&);
	};
}

#endif