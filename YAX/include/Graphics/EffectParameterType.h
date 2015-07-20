#ifndef _EFFECT_PARAMTER_TYPE_H
#define _EFFECT_PARAMTER_TYPE_H

#include "../Utils.h"

namespace YAX
{
    enum class EffectParameterType : ui32 
    {
        Bool,
        Int32,
        Single,
        Texture1D,
        Texture2D,
        Texture2D,
        TextureCube,
        Vector2,
        Vector3,
        Vector4,
        Void
    };
}


#endif