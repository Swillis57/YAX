#ifndef ALPHA8
#define ALPHA8

#include "IPackedVector.h"

namespace XNA
{
	struct Alpha8 : public IPackedVector<byte>
	{
		typedef IPackedVector<byte> Base;

		Alpha8(float);
		~Alpha8();

		byte PackedValue() override;
		void PackedValue(byte) override;

		float ToAlpha();
		void PackFromVector4(const Vector4&) override;
		Vector4 ToVector4() override;
		
		friend bool operator==(const Alpha8&, const Alpha8&);
		friend bool operator!=(const Alpha8&, const Alpha8&);
	};

	
	
}


#endif