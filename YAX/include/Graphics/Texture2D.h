#ifndef _TEXTURE_2D_H
#define _TEXTURE_2D_H

#include <exception>
#include <iosfwd>
#include <type_traits>
#include <vector>
#include "GLConversions.h"
#include "Texture.h"
#include "../Utils.h"

namespace YAX
{
    class GraphicsDevice;
    struct Rectangle;

    enum class SurfaceFormat : ui32;

    class Texture2D : public Texture
    {
    public:
        Texture2D(i32 w, i32 h);
        Texture2D(i32 w, i32 h, bool mipMap, SurfaceFormat fmt);
        Texture2D(const Texture2D&) = delete;
        Texture2D& operator=(const Texture2D&) = delete;
        Texture2D(Texture2D&&);
        Texture2D& operator=(Texture2D&&);
        ~Texture2D();

        Rectangle Bounds() const;
        i32 Height() const;
        i32 Width() const;

        static Texture2D FromStream(std::istream&);
        static Texture2D FromStream(std::istream&, i32 w, i32 h, bool unlockAspectRatio);


        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void GetData(i32 level, Rectangle* rect, std::vector<valType>& dest, i32 startIdx, i32 count) const
        {
            using T = typename valType::PackType;

            count = (i32)MathHelper::Clamp(count, 0, rect->Width() * rect->Height());
            T* data = new T[_width * _height];
            i32 levelWidth, levelHeight, originX, originY;
            if (rect)
            {
                levelWidth = rect->Width();
                levelHeight = rect->Height();
                originX = rect->X();
                originY = rect->Y();
            }
            else
            {
                levelWidth = MathHelper::Max(_width >> level, 1);
                levelHeight = MathHelper::Max(_height >> level, 1);
                originX = 0;
                originY = 0;
            }
            
            glBindTexture(GL_TEXTURE_2D, _id);
            //Make sure nothing is bound to the pixel pack buffer so we get
            //the correct behavior out of glGetTexImage
            glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
            glGetTexImage(GL_TEXTURE_2D, level, PixelDataFormat[valType::Format], PixelDataType[valType::Format], data);
            glPixelStorei(GL_PACK_ALIGNMENT, 4);
            glBindTexture(GL_TEXTURE_2D, 0);
            
            //Make sure the vector can hold all the pixels
            if (dest.capacity() < (size_t)(startIdx + count)) dest.resize(startIdx + count);
            
            i32 pixel = -1;
            for (i32 t = originY; t < levelHeight; t++)
            {
                for (i32 s = originX; s < levelWidth; s++)
                {
                    pixel++;
                    if (pixel > count) { t = levelHeight; break; }

                    i32 idx = s + t*_width;
                    dest[startIdx + idx].PackedValue(data[idx]);
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
            GetData(0, nullptr, dest, 0, _width * _height);
        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void GetData(std::vector<valType>& dest, i32 startIdx, i32 count) const
        {
            GetData(0, nullptr, dest, startIdx, count);
        }

        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(i32 level, Rectangle* rect, const std::vector<valType>& src, i32 startIdx, i32 count)
        {
            if (startIdx + count > src.size())
                throw std::invalid_argument("src must contain at least (startIdx + count) pixels.");

            using T = valType::PackType;
            i32 levelWidth, levelHeight, originX, originY;
            if (rect)
            {
                levelWidth = rect->Width();
                levelHeight = rect->Height(); 
                originX = rect->X();
                originY = rect->Y();
            }
            else
            {
                levelWidth = MathHelper::Max(_width >> level, 1);
                levelHeight = MathHelper::Max(_height >> level, 1);
                originX = 0;
                originY = 0;
            }

            //Need to extract the packed values from the vector because passing a pointer to the first member
            //(&src[0]) will also send the vtable pointer along with the pixel data
            T* data = new T[count];
            i32 pixel = -1;
            for (i32 t = originY; t < levelHeight; t++)
            {
                for (i32 s = originX; s < levelWidth; s++)
                {
                    pixel++;
                    if (pixel > count) { t = levelHeight; break; }

                    i32 idx = s + t*_width;
                    data[idx] = src[startIdx + idx].PackedValue(data[idx]);
                }
            }

            glBindTexture(GL_TEXTURE_2D, _id);
            glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
            glPixelStorei(GL_UNPACK_ALIGNMENT, PixelAlignment[valType::Format]);
            glTexSubImage2D(
                GL_TEXTURE_2D,
                level,
                originX,
                originY,
                levelWidth,
                levelHeight,
                PixelDataFormat[valType::Format],
                PixelDataType[valType::Format],
                data 
            );
            glBindTexture(GL_TEXTURE_2D, 0);
            glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

            delete data;
        }
                                                          
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(const std::vector<valType>& src)
        {
            SetData(0, nullptr, src, 0, src.size());
        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(const std::vector<valType>& src, i32 startIdx, i32 count)
        {
            SetData(0, nullptr, src, startIdx, count);
        }

        void SaveAsJpeg(std::ofstream&, i32 w, i32 h) const;
        void SaveAsPng(std::ofstream&, i32 w, i32 h) const;

    private:
        i32 _height, _width;


    };
}

#undef IsValidType
#endif