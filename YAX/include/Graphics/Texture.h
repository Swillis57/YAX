#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "../../../external/glew/include/GL/glew.h"
#include "GraphicsResource.h" 
#include "../Utils.h"

namespace YAX
{
    enum class SurfaceFormat : ui32;

    class Texture : public GraphicsResource
    {
    public:
        Texture();
        virtual ~Texture();
        
        Texture(const Texture&) = delete;
        Texture& operator=(const Texture&) = delete;
        Texture(Texture&&);
        Texture& operator=(Texture&&);

        void Bind(GLuint unit) const;
        SurfaceFormat Format() const;
        i32 LevelCount() const;

    protected:
        i32 CalcMaxMipLevel(i32 w, i32 h = 0, i32 d = 0);

        SurfaceFormat _format;
        i32 _levelCount;
        float _anisoLevel, _lodBias;
        GLuint _id;
        GLenum _type;

    };
}


#endif