#ifndef _BGRA4444_H
#define _BGRA4444_H

#include "IPackedVector.h"

namespace YAX
{
	struct Bgra4444 : public IPackedVector<ui16>
	{
		typedef IPackedVector<ui16> Base;

		Bgra4444(float b, float g, float r, float a);
		Bgra4444(const Vector4&);
		~Bgra4444();

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Bgra4444&, const Bgra4444&);
		friend bool operator!=(const Bgra4444&, const Bgra4444&);  

	private:
		void Pack(float b, float g, float r, float a);
	};
}


#endif