#ifndef _BGR_5_6_5_H
#define _BGR_5_6_5_H

#include "IPackedVector.h"


namespace YAX
{
	struct Bgr565 : IPackedVector<ui16>
	{
		typedef IPackedVector<ui16> Base;

		Bgr565(float b, float g, float r);
		Bgr565(const Vector3&);
		~Bgr565();

		Vector3 ToVector3() const;
		Vector4 ToVector4() const override;
		void PackFromVector4(const Vector4&) override;
		
		friend bool operator==(const Bgr565&, const Bgr565&);
		friend bool operator!=(const Bgr565&, const Bgr565&);

	private:
		void Pack(float b, float g, float r);

	};
}


#endif