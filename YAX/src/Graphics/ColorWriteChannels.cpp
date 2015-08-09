#include "Graphics/ColorWriteChannels.h"

namespace YAX
{
    ColorWriteChannels operator&(ColorWriteChannels lhs, ColorWriteChannels rhs)
    {
        return ((ColorWriteChannels)((ui32)lhs & (ui32)rhs));
    }

    ColorWriteChannels operator|(ColorWriteChannels lhs, ColorWriteChannels rhs)
    {
        return ((ColorWriteChannels)((ui32)lhs | (ui32)rhs));
    }
}