#ifndef _HALF_SINGLE_H
#define _HALF_SINGLE_H

#include "IPackedVector.h"

namespace YAX
{
	struct HalfSingle : IPackedVector<ui16>
	{
		typedef IPackedVector<ui16> Base;

		HalfSingle(float val);
		~HalfSingle();

		float ToSingle() const;
		void PackFromVector4(const Vector4&) override;
		Vector4 ToVector4() const override;

		friend bool operator==(const HalfSingle&, const HalfSingle&);
		friend bool operator!=(const HalfSingle&, const HalfSingle&);

	private:
		void Pack(float);
	};
}

#endif