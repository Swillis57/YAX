#ifndef _COLOR_WRITE_CHANNELS_H
#define _COLOR_WRITE_CHANNELS_H

#include "../Utils.h"

namespace YAX
{
    enum class ColorWriteChannels : ui32
    {
        None = 0,
        Red = 0x1,
        Green = 0x2, 
        Blue = 0x4,
        Alpha = 0x8,
        All = 0xF,
    };

    ColorWriteChannels operator&(ColorWriteChannels, ColorWriteChannels);
    ColorWriteChannels operator|(ColorWriteChannels, ColorWriteChannels);
}


#endif