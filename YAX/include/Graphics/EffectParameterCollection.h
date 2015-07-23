#ifndef _EFFECT_PARAMETER_COLLECTION_H
#define _EFFECT_PARAMETER_COLLECTION_H

#include <unordered_map>
#include <string>
#include "EffectParameter.h"

namespace YAX
{
    typedef std::unordered_map<std::string, EffectParameter> EffectParameterCollection;
}


#endif