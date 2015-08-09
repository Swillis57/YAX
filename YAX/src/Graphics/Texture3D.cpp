#include "Graphics/Texture3D.h"

#include "Graphics/GLConversions.h"
#include "MathHelper.h"
#include "Graphics/SurfaceFormat.h"

namespace YAX
{
    Texture3D::Texture3D(i32 w, i32 h, i32 d, bool mipMap, SurfaceFormat fmt)
        : Texture(),
        _width(w),
        _height(h),
        _depth(d)
    {
        _format = fmt;
        _levelCount = (mipMap ? CalcMaxMipLevel(w, h, d) : 1);
        _type = GL_TEXTURE_3D;

        glGenTextures(1, &_id);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_3D, _id);
        
        glTexImage3D(
            GL_TEXTURE_3D,
            0,
            (GLenum)_format,
            _width,
            _height,
            _depth,
            0,
            PixelDataFormat[_format],
            PixelDataType[_format],
            nullptr
        );
        
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_BASE_LEVEL, 0);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAX_LEVEL, _levelCount);

        glGenerateMipmap(GL_TEXTURE_3D);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, (mipMap
            ? GL_LINEAR_MIPMAP_LINEAR
            : GL_LINEAR
        ));

        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MAX_ANISOTROPY_EXT, MathHelper::Max(_anisoLevel, 1.0f));
        glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_LOD_BIAS, _lodBias);

        glBindTexture(GL_TEXTURE_3D, 0);
    }

    Texture3D::Texture3D(Texture3D&& old)
        : Texture(std::move(old)),
        _width(old._width),
        _height(old._height),
        _depth(old._depth)
    {
        old._width = 0;
        old._height = 0;
        old._depth = 0;
    }

    Texture3D& Texture3D::operator=(Texture3D&& old)
    {
        Texture::operator=(std::move(old));
        this->_width = old._width;
        this->_height = old._height;
        this->_depth = old._depth;

        old._width = 0;
        old._height = 0;
        old._depth = 0;

        return *this;
    }

    i32 Texture3D::Depth() const
    {
        return _depth;
    }

    i32 Texture3D::Height() const
    {
        return _height;
    }

    i32 Texture3D::Width() const
    {
        return _width;
    }


}