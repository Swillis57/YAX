#ifndef _ALPHA8_H
#define _ALPHA8_H

#include "IPackedVector.h"

namespace YAX
{
	struct Alpha8 : public IPackedVector<byte>
	{
		typedef IPackedVector<byte> Base;

		Alpha8(float val);
		~Alpha8();

		float ToAlpha() const;
		void PackFromVector4(const Vector4& source) override;
		Vector4 ToVector4() const override;
		
		friend bool operator==(const Alpha8&, const Alpha8&);
		friend bool operator!=(const Alpha8&, const Alpha8&);

	};

	
	
}


#endif