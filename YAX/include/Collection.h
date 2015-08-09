#ifndef _COLLECTION_H
#define _COLLECTION_H

#include <memory>
#include "Utils.h"

namespace YAX
{
    template<typename T>
    class Collection
    {
    public:
        Collection()
            : Collection(0)
        {}

        Collection(i32 num)
            : _elems(std::make_unique<T*[]>(num)),
            _max(num)
        {}

        i32 Max() const { return _max; }

        T*& operator[](ui32 i) { return _elems[i]; }

    private:
        i32 _max;
        std::unique_ptr<T*[]> _elems;
    };
}

#endif
