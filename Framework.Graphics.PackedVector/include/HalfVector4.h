#ifndef _HALF_VECTOR_4_H
#define _HALF_VECTOR_4_H


#include "IPackedVector.h"

namespace YAX
{
	struct HalfVector4 : public IPackedVector<ui64>
	{
		typedef IPackedVector<ui64> Base;

		HalfVector4(float val1, float val2, float val3, float val4);
		HalfVector4(const Vector4&);
		~HalfVector4();

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const HalfVector4&, const HalfVector4&);
		friend bool operator!=(const HalfVector4&, const HalfVector4&);
		
	private:
		void Pack(float, float, float, float);
	};
}

#endif