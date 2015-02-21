#ifndef _RG_32_H
#define _RG_32_H

#include "IPackedVector.h"

namespace YAX
{
	struct Rg32 : public IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		Rg32(float r, float g);
		Rg32(const Vector2&);
		~Rg32();

		Vector2 ToVector2() const;
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Rg32&, const Rg32&);
		friend bool operator!=(const Rg32&, const Rg32&);

	private:
		void Pack(float, float);
	};
}

#endif