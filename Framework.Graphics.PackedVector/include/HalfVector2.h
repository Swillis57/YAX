#ifndef _HALF_VECTOR_2_H
#define _HALF_VECTOR_2_H

#include "IPackedVector.h"

namespace YAX
{
	struct HalfVector2 : public IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		HalfVector2(float val1, float val2);
		HalfVector2(const Vector2&);
		~HalfVector2();

		Vector2 ToVector2() const;
		void PackFromVector4(const Vector4&) override;
		Vector4 ToVector4() const override;
		
		friend bool operator==(const HalfVector2&, const HalfVector2&);
		friend bool operator!=(const HalfVector2&, const HalfVector2&);
		
	private:
		void Pack(float, float);
	};
}

#endif