#ifndef _TEXTURE_CUBE_H
#define _TEXTURE_CUBE_H

#include <exception>
#include <type_traits>
#include <vector>
#include "Texture.h"
#include "../Utils.h"

namespace YAX
{
    enum class CubeMapFace : ui32;
    enum class SurfaceFormat : ui32;

    struct Rectangle;
    
    class TextureCube : public Texture
    {
    public:
        TextureCube(i32 size, bool mipMap, SurfaceFormat fmt);
        TextureCube(const TextureCube&) = delete;
        TextureCube& operator=(const TextureCube&) = delete;
        TextureCube(TextureCube&&);
        TextureCube& operator=(TextureCube&&);
        ~TextureCube();

        i32 Size() const;

        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void GetData(CubeMapFace face, i32 level, Rectangle* rect, std::vector<valType>& dest, i32 startIdx, i32 count) const
        {
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
                levelWidth = MathHelper::Max(_dim >> level, 1);
                levelHeight = MathHelper::Max(_dim >> level, 1);
                originX = 0;
                originY = 0;
            }
            T* data = new T[levelWidth * levelHeight];

            glBindTexture(GL_TEXTURE_CUBE_MAP, _id);
            glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
            glGetTexImage((GLenum)face, level, PixelDataFormat[valType::Format], PixelDataType[valType::Format], data);
            glPixelStorei(GL_PACK_ALIGNMENT, 4);
            glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

            if (startIdx + count > dest.capacity()) dest.resize(startIdx + count); 

            i32 pixel = -1;
            for (i32 y = originY; y < levelHeight; y++)
            {
                for (i32 x = originX; x < levelWidth; x++)
                {
                    pixel++;
                    if (pixel > count) { y = levelHeight; break; }

                    i32 idx = x + y * levelWidth;
                    dest[startIdx + idx].PackedValue(data[idx]);
                }
            }

            delete[] data;
        }

        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void GetData(CubeMapFace face, std::vector<valType>& dest) const
        {
            GetData(face, 0, nullptr, dest, 0, _dim*_dim);
        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void GetData(CubeMapFace face, std::vector<valType>& dest, i32 startIdx, i32 count) const
        {
            GetData(face, 0, nullptr, dest, startIdx, count);
        }

        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(CubeMapFace face, i32 level, Rectangle* rect, const std::vector<valType>& src, i32 startIdx, i32 count)
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
                levelWidth = MathHelper::Max(_dim >> level, 1);
                levelHeight = MathHelper::Max(_dim >> level, 1);
                originX = 0;
                originY = 0;
            }
            T* data = new T[levelWidth * levelHeight];

            i32 pixel = -1;
            for (i32 y = originY; y < levelHeight; y++)
            {
                for (i32 x = originX; x < levelWidth; x++)
                {
                    pixel++;
                    if (pixel > count) { y = levelHeight; break; }

                    i32 idx = x + y * levelWidth;
                    data[idx] = src[startIdx + idx].PackedValue();
                }
            }

            glBindTexture(GL_TEXTURE_CUBE_MAP, _id);
            glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
            glPixelStorei(GL_UNPACK_ALIGNMENT, PixelAlignment[valType::Format]);
            glTexSubImage2D(
                (GLenum)face,
                level,
                originX,
                originY,
                levelWidth,
                levelHeight,
                PixelDataFormat[valType::Format],
                PixelDataType[valType::Format],
                data
            );
            glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
            glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

            delete[] data;
        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(CubeMapFace face, const std::vector<valType>& src)
        {
            SetData(face, 0, nullptr, src, 0, src.size());
        }
        
        template<
            typename valType,
            typename = typename std::enable_if<std::is_base_of<PackedVector::IPackedVector, valType>::value>::type
        >
        void SetData(CubeMapFace face, const std::vector<valType>& src, i32 startIdx, i32 count)
        {
            SetData(face, 0, nullptr, src, startIdx, count);
        }

    private:
        i32 _dim;
    };
}


#endif