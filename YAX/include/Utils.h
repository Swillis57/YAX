#ifndef _UTILS_H
#define _UTILS_H

#include <cstdint>

namespace YAX
{
	typedef int16_t i16;
	typedef	int32_t i32;
	typedef int64_t i64;
	typedef uint16_t ui16;
	typedef uint32_t ui32;
	typedef uint64_t ui64;
	typedef unsigned char byte;

	//Casts a value of type F to one of type T
	//without changing the underlying bits
	template<typename T, typename F>
	T BitCast(F val)
	{
		static_assert(sizeof(T) == sizeof(F), "Types must be of the same size");

		T res;
		std::memcpy(&res, &val, sizeof(F));
		return res;
	}	

	template<size_t L, size_t R>
	struct is_leq_to { static const bool value = L <= R; };
}

#endif