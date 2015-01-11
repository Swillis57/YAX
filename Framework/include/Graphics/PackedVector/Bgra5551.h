#ifndef _BGRA5551_H
#define _BGRA5551_H

#include "IPackedVector.h"

namespace YAX
{
	struct Bgra5551 : IPackedVector<ui16>
	{						 
		typedef IPackedVector<ui16> Base;

		Bgra5551(float b, float g, float r, float a);
		Bgra5551(const Vector4&);
		~Bgra5551();

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Bgra5551&, const Bgra5551&);
		friend bool operator!=(const Bgra5551&, const Bgra5551&);

	private:
		void Pack(float b, float g, float r, float a);
	};
}


#endif