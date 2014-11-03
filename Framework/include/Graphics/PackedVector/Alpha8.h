#ifndef _ALPHA8_H
#define _ALPHA8_H

#include "IPackedVector.h"

namespace XNA
{
	struct Alpha8 : public IPackedVector<byte>
	{
		typedef IPackedVector<byte> Base;

		Alpha8(float);

		byte PackedValue() const override;
		void PackedValue(byte) override;

		float ToAlpha() const;
		void PackFromVector4(const Vector4&) override;
		Vector4 ToVector4() const override;
		
		friend bool operator==(const Alpha8&, const Alpha8&);
		friend bool operator!=(const Alpha8&, const Alpha8&);

	};

	
	
}


#endif