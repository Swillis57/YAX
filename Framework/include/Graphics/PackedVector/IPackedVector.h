#ifndef _IPACKEDVECTOR_H
#define _IPACKEDVECTOR_H

#include "../../Utils.h"

namespace XNA
{
	typedef char byte;
	class Vector2;
	class Vector3;
	class Vector4;

	namespace PackedVector
	{
		struct IPackedVector
		{
			virtual ~IPackedVector() {}
			virtual void PackFromVector4(const Vector4&) = 0;
			virtual Vector4 ToVector4() = 0;
		};

	}

	template<typename DType>
	struct IPackedVector : public PackedVector::IPackedVector
	{
		typedef PackedVector::IPackedVector IBase;
		virtual DType PackedValue() = 0;
		virtual void PackedValue(DType) = 0;

		IPackedVector()
			: IBase()
		{}

		virtual ~IPackedVector() {}

	protected:
		DType _packed;

	};
}



#endif