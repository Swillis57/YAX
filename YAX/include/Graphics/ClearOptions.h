#ifndef _CLEAR_OPTIONS_H
#define _CLEAR_OPTIONS_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
    enum class ClearOptions : ui32
    {
        DepthBuffer = GL_DEPTH_BUFFER_BIT,
        Stencil = GL_STENCIL_BUFFER_BIT,
        Target = GL_COLOR_BUFFER_BIT
    };

    ClearOptions operator|(ClearOptions lhs, ClearOptions rhs)
    {
        return (ClearOptions)((ui32)lhs | (ui32)rhs);
    }

    ClearOptions operator&(ClearOptions lhs, ClearOptions rhs)
    {
        return (ClearOptions)((ui32)lhs & (ui32)rhs);
    }

    ClearOptions operator|=(ClearOptions lhs, ClearOptions rhs)
    {
        return (lhs | rhs);
    }

    ClearOptions operator&=(ClearOptions lhs, ClearOptions rhs)
    {
        return (lhs & rhs);
    }

    ClearOptions operator~(ClearOptions rhs)
    {
        return (ClearOptions)(~((ui32)rhs));
    }
}


#endif