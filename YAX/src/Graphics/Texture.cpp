#include "Graphics/Texture.h"

#include "MathHelper.h"
#include "Graphics/SurfaceFormat.h"

namespace YAX
{
    Texture::Texture()
        : _format(SurfaceFormat::Color),
        _levelCount(0),
        _anisoLevel(4.0f),
        _lodBias(0.0f)
    {}

    Texture::~Texture()
    {
        if (_id != 0)
        {
            glDeleteTextures(1, &_id);
            _id = 0;
        }
    }

    Texture::Texture(Texture&& old)
        : _format(old._format),
        _levelCount(old._levelCount),
        _id(old._id),
        _anisoLevel(old._anisoLevel),
        _lodBias(old._lodBias)
    {
        old._id = 0;
        old._levelCount = 0;
        old._format = SurfaceFormat::Color;
    }

    Texture& Texture::operator=(Texture&& old)
    {
        this->_id = old._id;
        this->_levelCount = old._levelCount;
        this->_format = old._format;
        this->_anisoLevel = old._anisoLevel;
        this->_lodBias = old._lodBias;

        old._id = 0;
        old._levelCount = 0;
        old._format = SurfaceFormat::Color;
        
        return *this;
    }

    void Texture::Bind(GLuint unit) const
    {
        glActiveTexture(GL_TEXTURE0 + unit);
        glBindTexture(_type, _id);
    }

    SurfaceFormat Texture::Format() const
    {
        return _format;
    }

    i32 Texture::LevelCount() const
    {														  
        return _levelCount;
    }

    GLenum Texture::Type() const
    {
        return _type;
    }

    i32 Texture::CalcMaxMipLevel(i32 w, i32 h, i32 d)
    {
        i32 dim = MathHelper::Max(MathHelper::Max(w, h), d);

        i32 count;
        for (count = 1; (dim >>= 1) > 1; count++);

        return count;
    }
}