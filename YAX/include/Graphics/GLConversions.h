#ifndef _GLCONVERSIONS_H
#define _GLCONVERSIONS_H

#include <unordered_map>
#include "SurfaceFormat.h"

namespace YAX
{
    static std::unordered_map<SurfaceFormat, GLenum> PixelDataFormat = 
    {
        { SurfaceFormat::Color,				GL_RGBA },
        { SurfaceFormat::Bgr565,			GL_BGR },
        { SurfaceFormat::Bgr4444,			GL_BGRA },
        { SurfaceFormat::Bgra5551,			GL_BGRA },
        { SurfaceFormat::NormalizedByte2,	GL_RG },
        { SurfaceFormat::NormalizedByte4,	GL_RGBA },
        { SurfaceFormat::Rgba1010102,		GL_RGBA },
        { SurfaceFormat::Rg32,				GL_RG },
        { SurfaceFormat::Rgba64,			GL_RGBA },
        { SurfaceFormat::Alpha8,			GL_RED },
        { SurfaceFormat::Single,			GL_RED },
        { SurfaceFormat::Vector2,			GL_RG },
        { SurfaceFormat::Vector4,			GL_RGBA },
        { SurfaceFormat::HalfSingle,		GL_RED },
        { SurfaceFormat::HalfVector2,		GL_RG },
        { SurfaceFormat::HalfVector4,		GL_RGBA }    
    };

    static std::unordered_map<SurfaceFormat, GLenum> PixelDataType = 
    {
        { SurfaceFormat::Color,				GL_UNSIGNED_BYTE },
        { SurfaceFormat::Bgr565,			GL_UNSIGNED_SHORT_5_6_5 },
        { SurfaceFormat::Bgr4444,			GL_UNSIGNED_SHORT_4_4_4_4 },
        { SurfaceFormat::Bgra5551,			GL_UNSIGNED_SHORT_5_5_5_1 },
        { SurfaceFormat::NormalizedByte2,	GL_BYTE },
        { SurfaceFormat::NormalizedByte4,	GL_BYTE },
        { SurfaceFormat::Rgba1010102,		GL_UNSIGNED_INT_10_10_10_2 },
        { SurfaceFormat::Rg32,				GL_UNSIGNED_SHORT },
        { SurfaceFormat::Rgba64,			GL_UNSIGNED_SHORT },
        { SurfaceFormat::Alpha8,			GL_UNSIGNED_BYTE },
        { SurfaceFormat::Single,			GL_FLOAT },
        { SurfaceFormat::Vector2,			GL_FLOAT },
        { SurfaceFormat::Vector4,			GL_FLOAT },
        { SurfaceFormat::HalfSingle,		GL_HALF_FLOAT },
        { SurfaceFormat::HalfVector2,		GL_HALF_FLOAT },
        { SurfaceFormat::HalfVector4,		GL_HALF_FLOAT }
    };

    static std::unordered_map<SurfaceFormat, i32> PixelAlignment = 
    {
        { SurfaceFormat::Color,				4 },
        { SurfaceFormat::Bgr565,			2 },
        { SurfaceFormat::Bgr4444,			2 },
        { SurfaceFormat::Bgra5551,			2 },
        { SurfaceFormat::NormalizedByte2,	2 },
        { SurfaceFormat::NormalizedByte4,	4 },
        { SurfaceFormat::Rgba1010102,		4 },
        { SurfaceFormat::Rg32,				4 },
        { SurfaceFormat::Rgba64,			8 },
        { SurfaceFormat::Alpha8,			1 },
        { SurfaceFormat::Single,			4 },
        { SurfaceFormat::Vector2,			8 },
        { SurfaceFormat::Vector4,			4 },
        { SurfaceFormat::HalfSingle,		2 },
        { SurfaceFormat::HalfVector2,		4 },
        { SurfaceFormat::HalfVector4,		8 }   
    };
}

#endif