#ifndef _IPACKEDVECTOR_H
#define _IPACKEDVECTOR_H

#include <limits>
#include <type_traits>
#include "../../Framework/include/Utils.h"

#define READBITS_STATIC(field, mask, offset) ((field & (mask << offset)) >> offset)
#define READBITS(mask, offset) READBITS_STATIC(_packed, mask, offset)

#define WRITEBITS_STATIC(field, bits, offset) (field |= bits); (field <<= offset);
#define WRITEBITS(bits, offset) WRITEBITS_STATIC(_packed, bits, offset); 

namespace YAX
{
	struct Vector2;
	struct Vector3;
	struct Vector4;

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

		DType PackedValue() const { return _packed; };
		void PackedValue(DType newPacked) { _packed = newPacked; }

	protected:
		DType _packed;

	};
}



#endif