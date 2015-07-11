#ifndef _EFFECT_PARAMETER_CLASS_H
#define _EFFECT_PARAMETER_CLASS_H

#include "../Utils.h"

namespace YAX
{
    enum class EffectParameterClass : ui32 
    {
        Array,
        Matrix,
        Scalar,
        Struct,
        Texture,
        Vector
    };
}


#endif