#include "../../include/Graphics/Texture2D.h"

#include <exception>
#include <memory>
#include "../../include/Color.h"
#include "../../include/MathHelper.h"
#include "../../include/Rectangle.h"
#include "../../../external/stb_image/include/stb_image.h"
#include "../../../external/stb_image/include/stb_image_resize.h"
#define STBIW_USE_STREAMS
#include "../../../external/stb_image/include/stb_image_write.h"
#include "../../include/Graphics/SurfaceFormat.h"

namespace YAX
{
    Texture2D::Texture2D(i32 w, i32 h, bool mipMap, SurfaceFormat fmt)
        : Texture(),
        _width(w),
        _height(h)
    {
        _format = fmt;
        _levelCount = (mipMap ? CalcMaxMipLevel(w, h) : 1);
        _type = GL_TEXTURE_2D;

        glGenTextures(1, &_id);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, _id);

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            (GLenum)fmt,
            w,
            h,
            0,
            PixelDataFormat[fmt],
            PixelDataType[fmt],
            nullptr
        );
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, _levelCount);

        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (mipMap
            ? GL_LINEAR_MIPMAP_LINEAR
            : GL_LINEAR
        ));

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, MathHelper::Max(_anisoLevel, 1.0f));
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, _lodBias);
        
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Texture2D::Texture2D(i32 w, i32 h)
        : Texture2D(w, h, false, SurfaceFormat::Color)
    {}

    Texture2D::Texture2D(Texture2D&& old)
        : Texture(std::move(old)),
        _width(old._width),
        _height(old._height)
    {
        old._width = 0;
        old._height = 0;
    }

    Texture2D& Texture2D::operator=(Texture2D&& old)
    {
        Texture::operator=(std::move(old));
        this->_width = old._width;
        this->_height = old._height;
        return *this;
    }

    Rectangle Texture2D::Bounds() const
    {
        return Rectangle(0, 0, _width, _height);
    }

    i32 Texture2D::Height() const
    {
        return _height;
    }

    i32 Texture2D::Width() const
    {
        return _width;
    }

    //Anonymous namespace for internal texture creation functions
    namespace
    {
        //Reads an image from a std::istream and decodes it with stb_image
        stbi_uc* ReadImage(std::istream& in, i32* x, i32* y, i32* numC) 
        {
            stbi_set_unpremultiply_on_load(1);

            in.seekg(std::ios::end);
            auto len = in.tellg();
            in.seekg(std::ios::beg);

            char* streamData = new char[len];
            in.read(streamData, len);

            auto img = stbi_load_from_memory((stbi_uc*)streamData, len, x, y, numC, 4);
            
            delete[] streamData;
            return img;
        }

        //Takes an stb_image-loaded texture and uploads it to the texture object
        void UploadImage(stbi_uc* data, GLuint id, i32 w, i32 h)
        {
            if (data != nullptr)
            {
                glBindTexture(GL_TEXTURE_2D, id);
                glTexImage2D(
                    GL_TEXTURE_2D,
                    0,
                    (GLenum)SurfaceFormat::Color,
                    w,
                    h,
                    0,
                    PixelDataFormat[SurfaceFormat::Color],
                    PixelDataType[SurfaceFormat::Color],
                    data
                );
            }
            else
            {
                throw std::runtime_error("Error loading image from stream.");
            }
        }
    }

    Texture2D Texture2D::FromStream(std::istream& in)
    {
        i32 xDim = 0, yDim = 0, numComponents = 0;
        auto imgData = ReadImage(in, &xDim, &yDim, &numComponents);
        
        Texture2D tex { xDim, yDim, false, SurfaceFormat::Color };
        UploadImage(imgData, tex._id, xDim, yDim);
        stbi_image_free(imgData);

        delete[] imgData;
        return tex;
    }

    Texture2D Texture2D::FromStream(std::istream& in, i32 w, i32 h, bool unlockAspectRatio)
    {
        i32 xDim = 0, yDim = 0, numComponents = 0;
        auto imgData = ReadImage(in, &xDim, &yDim, &numComponents);
        unsigned char* resizedImage;

        //If the aspect ratio is unlocked, resize the image to exactly the given dimensions
        //Else calculate a new height that preserves the aspect ratio
        h = (i32)(unlockAspectRatio ? h : w * ((float)yDim / xDim));

        resizedImage = new unsigned char[w * h];

        stbir_resize_uint8(
            imgData,
            xDim,
            yDim,
            0,
            resizedImage,
            w,
            h,
            0,
            4
        );

        Texture2D tex { xDim, yDim, false, SurfaceFormat::Color };
        UploadImage((stbi_uc*)resizedImage, tex._id, w, h);
        stbi_image_free(imgData);
        delete[] resizedImage;

        return tex;
    }

    void Texture2D::SaveAsJpeg(std::ofstream& out, i32 w, i32 h) const
    {
        throw std::exception("Not Implemented");
    }

    void Texture2D::SaveAsPng(std::ofstream& out, i32 w, i32 h) const
    {
        std::vector<Color> pixels;
        pixels.resize(_width * _height);
        GetData(pixels);

        byte* data = new byte[_width * _height * 4];
        for (size_t i = 0; i < pixels.size(); i++)
        {
            data[i] = pixels[i].R();
            data[i+1] = pixels[i+1].G();
            data[i+2] = pixels[i+2].B();
            data[i+3] = pixels[i+3].A();
        }

        stbi_write_png(out, _width, _height, 4, data, 0);
    }


}	