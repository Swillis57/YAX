#ifndef _RG_32_H
#define _RG_32_H

#include "IPackedVector.h"

namespace YAX
{
	struct Rg32 : public IPackedVector<ui32>
	{
		Rg32(float, float);
		Rg32(const Vector2&);

		Vector2 ToVector2() const;
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Rg32&, const Rg32&);
		friend bool operator!=(const Rg32&, const Rg32&);
	};
}

#endif