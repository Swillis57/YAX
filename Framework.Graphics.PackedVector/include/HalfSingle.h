#ifndef _HALF_SINGLE_H
#define _HALF_SINGLE_H

#include "IPackedVector.h"

namespace YAX
{
	struct HalfSingle : public IPackedVector<ui16>
	{
		typedef IPackedVector<ui16> Base;

		static ui16 Pack(float);
		static float Unpack(ui16);

		HalfSingle(float val);
		~HalfSingle();

		float ToSingle() const;
		void PackFromVector4(const Vector4&) override;
		Vector4 ToVector4() const override;

		friend bool operator==(const HalfSingle&, const HalfSingle&);
		friend bool operator!=(const HalfSingle&, const HalfSingle&);
	};
}

#endif