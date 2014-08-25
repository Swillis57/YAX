#ifndef BYTE_4
#define BYTE_4

#include "IPackedVector.h"

namespace XNA
{
	struct Byte4 : IPackedVector<ui32>
	{
		Byte4(float, float, float, float);
		Byte4(const Vector4&);
		~Byte4();

		ui32 PackedValue() override;
		void PackedValue(ui32) override;

		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Byte4&, const Byte4&);
		friend bool operator!=(const Byte4&, const Byte4&);
	};
}

#endif