#ifndef _SHORT_2_H
#define _SHORT_2_H

#include "IPackedVector.h"

namespace YAX
{
	struct Short2 : public IPackedVector<ui32>
	{
		typedef IPackedVector<ui32> Base;

		Short2(float, float);
		Short2(const Vector2&);
		~Short2();

		Vector2 ToVector2() const;
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;

		friend bool operator==(const Short2&, const Short2&);
		friend bool operator!=(const Short2&, const Short2&);
		
	private:
		void Pack(float, float);
	};
}

#endif