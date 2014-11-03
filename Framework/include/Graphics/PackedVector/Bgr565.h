#ifndef _BGR_5_6_5_H
#define _BGR_5_6_5_H

#include "IPackedVector.h"


namespace XNA
{
	struct Bgr565 : IPackedVector<ui16>
	{
		Bgr565(float, float, float);
		Bgr565(const Vector3&);

		ui16 PackedValue() const override;
		void PackedValue(ui16) override;

		Vector3 ToVector3() const;
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;
		
		friend bool operator==(const Bgr565&, const Bgr565&);
		friend bool operator!=(const Bgr565&, const Bgr565&);

	};
}


#endif