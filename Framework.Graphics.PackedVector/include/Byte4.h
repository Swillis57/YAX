#ifndef _BYTE_4_H
#define _BYTE_4_H

#include "IPackedVector.h"

namespace YAX
{
	struct Byte4 : IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		Byte4(float r, float g, float b, float a);
		Byte4(const Vector4&);
		~Byte4();

		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Byte4&, const Byte4&);
		friend bool operator!=(const Byte4&, const Byte4&);

	private:
		void Pack(float, float, float, float);
	};
}

#endif