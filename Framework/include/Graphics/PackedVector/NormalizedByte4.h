#ifndef NORMALIZED_BYTE_4
#define NORMALIZED_BYTE_4

#include "IPackedVector.h"

namespace XNA
{
	struct NormalizedByte4 : IPackedVector<ui32>
	{
		NormalizedByte4(float, float, float, float);
		NormalizedByte4(const Vector4&);
		~NormalizedByte4();

		ui32 PackedValue() override;
		void PackedValue(ui32) override;

		
		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const NormalizedByte4&, const NormalizedByte4&);
		friend bool operator!=(const NormalizedByte4&, const NormalizedByte4&);
	};
}

#endif

