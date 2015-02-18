#ifndef _NORMALIZED_BYTE_4_H
#define _NORMALIZED_BYTE_4_H

#include "IPackedVector.h"

namespace YAX
{
	struct NormalizedByte4 : IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		NormalizedByte4(float val1, float val2, float val3, float val4);
		NormalizedByte4(const Vector4&);
		~NormalizedByte4();
		
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const NormalizedByte4&, const NormalizedByte4&);
		friend bool operator!=(const NormalizedByte4&, const NormalizedByte4&);
		
	private:
		void Pack(float, float, float, float);
	};
}

#endif

