#ifndef _IPACKEDVECTOR_H
#define _IPACKEDVECTOR_H

#include <type_traits>
#include "../../Utils.h"

namespace YAX
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
			virtual Vector4 ToVector4() const = 0;
		};

	}

	template<typename DType>
	struct IPackedVector : public PackedVector::IPackedVector
	{
		static_assert(std::is_integral<DType>::value, "IPackedVector can only pack into integral types.");
		typedef PackedVector::IPackedVector IBase;

		IPackedVector()
			: IBase()
		{}

		virtual ~IPackedVector() {}

		virtual DType PackedValue() const = 0;
		virtual void PackedValue(DType) = 0;

	protected:
		DType _packed;

	};
}



#endif