#include "Graphics/TextureCube.h"

#include "MathHelper.h"
#include "Rectangle.h"
#include "Graphics/CubeMapFace.h"
#include "Graphics/GLConversions.h"
#include "Graphics/SurfaceFormat.h"

namespace YAX
{
    TextureCube::TextureCube(i32 size, bool mipMap, SurfaceFormat fmt)
        : Texture(),
        _dim(size)
    {
        _format = fmt;
        _levelCount = CalcMaxMipLevel(_dim);
        _type = GL_TEXTURE_CUBE_MAP;

        glGenTextures(1, &_id);
        glBindTexture(GL_TEXTURE_CUBE_MAP, _id);

        for (i32 i = 0; i < 6; i++)
        {
            glTexImage2D(
                (GLenum)CubeMapFace::PositiveX + i,
                0,
                (GLenum)SurfaceFormat::Color,
                _dim,
                _dim,
                0,
                PixelDataFormat[SurfaceFormat::Color],
                PixelDataType[SurfaceFormat::Color],
                nullptr
            );
        }

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BASE_LEVEL, 0);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_LEVEL, _levelCount);

        glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, (mipMap
            ? GL_LINEAR_MIPMAP_LINEAR
            : GL_LINEAR
        ));

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_ANISOTROPY_EXT, MathHelper::Max(_anisoLevel, 1.0f));
        glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_LOD_BIAS, _lodBias);

        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    }

    TextureCube::TextureCube(TextureCube&& old)
        : Texture(std::move(old)),
        _dim(old._dim)
    {
        old._dim = 0;
    }

    TextureCube& TextureCube::operator=(TextureCube&& old)
    {
        Texture::operator=(std::move(old));
        _dim = old._dim;
        old._dim = 0;
        return *this;
    }

    i32 TextureCube::Size() const
    {
        return _dim;
    }
}