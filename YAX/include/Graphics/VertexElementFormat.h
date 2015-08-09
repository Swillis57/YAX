#ifndef _VERTEX_ELEMENT_FORMAT_H
#define _VERTEX_ELEMENT_FORMAT_H

#include <unordered_map>

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
    enum class VertexElementFormat : GLenum
    {
        Single = GL_FLOAT,	          
        Vector2 = GL_FLOAT,	          
        Vector3 = GL_FLOAT,	          
        Vector4 = GL_FLOAT,	          
        HalfVector2 = GL_HALF_FLOAT,       
        HalfVector4 = GL_HALF_FLOAT,       
        Color = GL_UNSIGNED_BYTE,		      
        NormalizedShort2 = GL_FLOAT,  
        NormalizedShort4 = GL_FLOAT,  
        Short2 = GL_SHORT,		      
        Short4 = GL_SHORT,		      
        Byte4 = GL_UNSIGNED_BYTE	  
    }; 

    static std::unordered_map<VertexElementFormat, ui32> VertexFormatComponents =
    {
        { VertexElementFormat::Single, 1 },
        { VertexElementFormat::Vector2, 2 },
        { VertexElementFormat::Vector3, 3 },
        { VertexElementFormat::Vector4, 4 },
        { VertexElementFormat::HalfVector2, 2 },
        { VertexElementFormat::HalfVector4, 4 },
        { VertexElementFormat::Color, 4 },
        { VertexElementFormat::NormalizedShort2, 2 },
        { VertexElementFormat::NormalizedShort4, 4 },
        { VertexElementFormat::Short2, 2 },
        { VertexElementFormat::Short4, 4 },
        { VertexElementFormat::Byte4, 4 }
    };

    static bool Normalized(VertexElementFormat fmt)
    {
        return (fmt == VertexElementFormat::Color
            || fmt == VertexElementFormat::NormalizedShort2
            || fmt == VertexElementFormat::NormalizedShort4);
    }
}


#endif