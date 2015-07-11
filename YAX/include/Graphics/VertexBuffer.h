#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include <exception>
#include <type_traits>
#include <vector>

#include "../../../external/glew/include/GL/glew.h"
#include "GraphicsResource.h"
#include "PackedVector/IPackedVector.h"
#include "IVertexType.h"
#include "VertexDeclaration.h"
#include "../Utils.h"

namespace YAX
{
    enum class BufferUsage : ui32;

    class VertexBuffer : public GraphicsResource
    {
    public:
        VertexBuffer(YAX::VertexDeclaration decl, i32 vertCount, BufferUsage usage);
        VertexBuffer(const VertexBuffer&) = delete;
        VertexBuffer& operator=(const VertexBuffer&) = delete;
        VertexBuffer(VertexBuffer&&);
        VertexBuffer& operator=(VertexBuffer&&);

        YAX::BufferUsage BufferUsage() const;
        i32 VertexCount() const;
        YAX::VertexDeclaration VertexDeclaration() const;


        template<typename T>
        void GetData(i32 offsetInBytes, std::vector<T>& dest, i32 startIdx, i32 count, i32 stride) const
        {
            if (_usage == BufferUsage::WriteOnly)
                throw std::runtime_error("Cannot read from a write-only buffer.");

            if (offsetInBytes < 0 || stride < 0)
                throw std::invalid_argument("offsetInBytes and stride must be greater than or equal to zero.");
            
            if (count > 1 && count*stride > _vertCount*_vertDecl.VertexStride())
                throw std::invalid_argument("The vertex stride is larger than the vertex buffer.");

            if (stride < sizeof(T))
                throw std::invalid_argument("The stride is too small for the type of data requested.");

            T* data = new T[count * _vertDecl.VertexStride()];
            glBindBuffer(GL_ARRAY_BUFFER, _id);
            glGetBufferSubData(GL_ARRAY_BUFFER, offsetInBytes, count * _vertDecl.VertexStride(), data);
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            if (sizeof(T) == stride)
            {
                dest.insert(startIdx, data, data + count);
            }
            else
            {
                if (startIdx + count > dest.size()) dest.resize(startIdx + count);
                
                byte* chunk = reinterpret_cast<byte*>(data);
                for (i32 i = 0; i < count; i++, chunk += stride)
                {
                    dest[startIdx + i] = *reinterpret_cast<T*>(chunk);
                }
            }

            delete[] data;
        }

        template<typename T>
        void GetData(std::vector<T>& dest) const
        {
            GetData(0, dest, 0, _vertCount, sizeof(T));
        }
        
        template<typename T>
        void GetData(std::vector<YAX::VertexDeclaration>& dest, i32 startIdx, i32 count) const
        {
            GetData(0, dest, startIdx, count, sizeof(T));
        }

        template<typename T>
        void SetData(i32 offsetInBytes, const std::vector<T>& src, i32 startIdx, i32 count, i32 stride)
        {
            if (src.size() < count + startIdx)
                throw std::invalid_argument("The vector is not the correct size for the amount of data requested.");

            if (stride < sizeof(T))
                throw std::invalid_argument("The stride is too small for the type of data requested.");
            
            if (count > 1 && count*stride > _vertCount*_vertDecl.VertexStride())
                throw std::invalid_argument("The vertex stride is larger than the vertex buffer.");

            i32 isBound = 0;
            glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &isBound);
            if (isBound == _id)
                throw std::runtime_error("Cannot modify a buffer while it is in use.");

            glBindBuffer(GL_ARRAY_BUFFER, _id);
            glBufferSubData(GL_ARRAY_BUFFER, offsetInBytes, count * stride, &src[startIdx]);
            glBindBuffer(GL_ARRAY_BUFFER, 0);

        }
        
        template<typename T>
        void SetDate(const std::vector<T>& src)
        {
            SetData(0, src, 0, src.size(), sizeof(T));
        }
        
        template<typename T>
        void SetData(const std::vector<T>&, i32 startIdx, i32 count)
        {
            SetData(0, src, startIdx, count, sizeof(T));
        }

    protected:
        YAX::BufferUsage _usage;
        i32 _vertCount;
        YAX::VertexDeclaration _vertDecl;
        GLuint _id;
    };
}


#endif