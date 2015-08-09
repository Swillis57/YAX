#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "../../../external/glew/include/GL/glew.h"
#include "../Utils.h"

namespace YAX
{
    enum class SurfaceFormat : ui32;

    class Texture
    {
    public:
        Texture();
        virtual ~Texture();
        
        Texture(const Texture&) = delete;
        Texture& operator=(const Texture&) = delete;
        Texture(Texture&&);
        Texture& operator=(Texture&&);

        void Bind(GLuint) const;
        SurfaceFormat Format() const;
        i32 LevelCount() const;
        GLenum Type() const;

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