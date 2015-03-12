#ifndef _RGBA_10_10_10_2_H
#define _RGBA_10_10_10_2_H

#include "IPackedVector.h"

namespace YAX
{
	struct Rgba1010102 : public IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		Rgba1010102(float, float, float, float);
		Rgba1010102(const Vector4&);
		~Rgba1010102();

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Rgba1010102&, const Rgba1010102&);
		friend bool operator!=(const Rgba1010102&, const Rgba1010102&);
	
	private:
		void Pack(float, float, float, float);
	};
}

#endif