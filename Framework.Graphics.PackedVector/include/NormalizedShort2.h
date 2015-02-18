#ifndef _NORMALIZED_SHORT_2_H
#define _NORMALIZED_SHORT_2_H

#include "IPackedVector.h"

namespace YAX
{
	struct NormalizedShort2 : IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		NormalizedShort2(float val1, float val2);
		NormalizedShort2(const Vector2&);
		~NormalizedShort2();

		Vector2 ToVector2() const;
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const NormalizedShort2&, const NormalizedShort2&);
		friend bool operator!=(const NormalizedShort2&, const NormalizedShort2&);
	
	private:
		void Pack(float, float);
	};
}

#endif