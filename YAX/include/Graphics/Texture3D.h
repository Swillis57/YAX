#ifndef _TEXTURE_3D_H
#define _TEXTURE_3D_H

#include <exception>
#include <type_traits>
#include <vector>
#include "Texture.h"
#include "../Utils.h"

namespace YAX
{
    enum class SurfaceFormat : ui32;

    class Texture3D : public Texture
    {
    public:
        Texture3D(i32 w, i32 h, i32 d, bool mipMap, SurfaceFormat fmt);
        Texture3D(const Texture3D&) = delete;
        Texture3D& operator=(const Texture3D&) = delete;
        Texture3D(Texture3D&&);
        Texture3D& operator=(Texture3D&&);
        ~Texture3D() = default;

        i32 Depth() const;

        i32 Height() const;

        i32 Width() const;

        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void GetData(i32 level, i32 left, i32 top, i32 right, i32 bottom, i32 front, i32 back, std::vector<valType>& dest, i32 startIdx, i32 count) const
        {
            if (left > right || bottom > top || front > back)
                throw std::invalid_argument("The dimensions of GetData must follow: left <= right, bottom <= top, front <= back.");

            using T = typename valType::PackType;
            i32 sourceWidth = right - left;
            i32 sourceHeight = top - bottom;
            i32 sourceDepth = back - front;

            count = (i32)MathHelper::Clamp(count, 0, sourceWidth * sourceHeight * sourceDepth);
            T* data = new T[count];

            glBindTexture(GL_TEXTURE_2D, _id);
            //Make sure nothing is bound to the pixel pack buffer so we get
            //the correct behavior out of glGetTexImage
            glBindTexture(GL_PIXEL_PACK_BUFFER, 0);
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
            glGetTexImage(GL_TEXTURE_3D, level, PixelDataFormat[valType::Format], PixelDataType[valType::Format], data);
            glPixelStorei(GL_PACK_ALIGNMENT, 4);
            glBindTexture(GL_TEXTURE_3D, 0);

            //Make sure the vector can hold all the pixels
            if (dest.capacity() < (size_t)(startIdx + count)) dest.resize(startIdx + count);

            i32 pixel = -1;
            for (i32 r = front; r < sourceDepth; r++)
            {
                for (i32 t = bottom; t < sourceHeight; t++)
                {
                    for (i32 s = left; s < sourceWidth; s++)
                    {
                        pixel++;
                        if (pixel > count) { t = sourceHeight; r = sourceDepth; break; }

                        i32 idx = s + t*_width + r*_width*_height;
                        dest[startIdx + idx].PackedValue(data[idx]);
                    }
                }
            }

            delete[] data;
        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void GetData(std::vector<valType>& dest) const
        {
            GetData(0, 0, _height, _width, 0, 0, _depth, dest, 0, _width * _height * _depth); 
        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void GetData(std::vector<valType>& dest, i32 startIdx, i32 count) const
        {
            GetData(0, 0, _height, _width, 0, 0, _depth, dest, startIdx, count);
        }

        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(i32 level, i32 left, i32 top, i32 right, i32 bottom, i32 front, i32 back, std::vector<valType>& src, i32 startIdx, i32 count)
        {
            if (left > right || bottom > top || front > back)
                throw std::invalid_argument("The dimensions of GetData must follow: left <= right, bottom <= top, front <= back.");
        
            using T = valType::PackType;
            i32 destWidth = right - left;
            i32 destHeight = top - bottom;
            i32 destDepth = back - front;

            count = (i32)MathHelper::Clamp(count, 0, destWidth * destHeight * destDepth);
            T* data = new T[count];

            //Extract the packed values to avoid copying vtable pointers
            i32 pixel = -1;
            for (i32 r = front; r < destDepth; r++)
            {
                for (i32 t = bottom; t < destHeight; t++)
                {
                    for (i32 s = left; s < destWidth; s++)
                    {
                        pixel++;
                        if (pixel > count) { t = destHeight; r = destDepth; break; }

                        i32 idx = s + t*_width + r*_width*_height;
                        data[idx] = src[startIdx + idx].PackedValue();
                    }
                }
            }

            glBindTexture(GL_TEXTURE_3D, _id);
            glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
            glPixelStorei(GL_UNPACK_ALIGNMENT, PixelAlignment[valType::Format]);
            glTexSubImage3D(
                GL_TEXTURE_3D,
                level,
                left,
                bottom,
                front,
                destWidth,
                destHeight,
                destDepth,
                PixelFormat[valType::Format],
                PixelDataType[valType::Format],
                data
            );
            glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
            glBindTexture(GL_TEXTURE_3D, 0);

            delete[] data;

        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(const std::vector<valType>& src)
        {
            SetData(0, 0, _height, _width, 0, 0, _depth, src, 0, src.size());
        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(const std::vector<valType>& src, i32 startIdx, i32 count)
        {
            SetData(0, 0, _height, _width, 0, 0, _depth, src, startIdx, count);
        }

    private:
        i32 _depth, _width, _height;
    };
}


#endif