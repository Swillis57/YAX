#ifndef _VERTEX_ELEMENT_FORMAT_H
#define _VERTEX_ELEMENT_FORMAT_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
    enum class VertexElementFormat : ui32
    {
        Single,	            //<GL_FLOAT, 1>
        Vector2,	        //<GL_FLOAT, 2>
        Vector3,	        //<GL_FLOAT, 3>
        Vector4,	        //<GL_FLOAT, 4>
        HalfVector2,        //<GL_FLOAT, 2>
        HalfVector4,        //<GL_FLOAT, 4>
        Color,			    //<GL_UNSIGNED_BYTE, 4> 
        NormalizedShort2,   //<GL_UNSIGNED_SHORT, 2>
        NormalizedShort4,   //<GL_UNSIGNED_SHORT, 2>
        Short2,		        //<GL_SHORT, 2>			
        Short4,		        //<GL_SHORT, 4>			
        Byte4		        //<GL_UNSIGNED_BYTE, 4> 
    };  
}


#endif