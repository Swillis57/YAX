#ifndef BGR_5_6_5
#define BGR_5_6_5

#include "IPackedVector.h"

namespace XNA
{
	struct Bgr565 : IPackedVector<ui16>
	{
		Bgr565(float, float, float);
		Bgr565(const Vector3&);
		~Bgr565();

		ui16 PackedValue() override;
		void PackedValue(ui16) override;

		Vector3 ToVector3();
		Vector4 ToVector4() override;
		void PackFromVector4(const Vector4&) override;
		
		friend bool operator==(const Bgr565&, const Bgr565&);
		friend bool operator!=(const Bgr565&, const Bgr565&);
	};
}


#endif