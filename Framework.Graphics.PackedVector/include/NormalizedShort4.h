#ifndef _NORMALIZED_SHORT_4_H
#define _NORMALIZED_SHORT_4_H

#include "IPackedVector.h"

namespace YAX
{
	struct NormalizedShort4 : public IPackedVector<ui64>
	{
		typedef IPackedVector<ui64> Base;

		NormalizedShort4(float, float, float, float);
		NormalizedShort4(const Vector4&);

		~NormalizedShort4();

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const NormalizedShort4&, const NormalizedShort4&);
		friend bool operator!=(const NormalizedShort4&, const NormalizedShort4&);
	
	private:
		void Pack(float, float, float, float);
	};
}

#endif

