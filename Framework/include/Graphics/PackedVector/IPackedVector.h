#ifndef _IPACKEDVECTOR_H
#define _IPACKEDVECTOR_H

#include <type_traits>
#include "../../Utils.h"

#define READBITS(mask, offset) ((_packed & (mask << offset)) >> offset)
#define WRITEBITS(bits, offset) (_packed |= bits); (_packed <<= offset); 

namespace YAX
{
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

		DType PackedValue() const { return _packed };
		void PackedValue(DType newPacked) { _packed = newPacked; }

	protected:
		DType _packed;

	};
}



#endif