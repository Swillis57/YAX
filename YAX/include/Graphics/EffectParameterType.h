#ifndef _EFFECT_PARAMETER_TYPE_H
#define _EFFECT_PARAMETER_TYPE_H

#include "../Utils.h"

namespace YAX
{
    enum class EffectParameterType : ui32 
    {
        Bool,
        Int32,
        Matrix,
        Single,
        Texture1D,
        Texture2D,
        Texture3D,
        TextureCube,
        Vector2,
        Vector3,
        Vector4
    };
}


#endif