#ifndef _DYNAMIC_INDEX_BUFFER_H
#define _DYNAMIC_INDEX_BUFFER_H

#include <vector>
#include "IndexBuffer.h"
#include "SetDataOptions.h"
#include "../Utils.h"

namespace YAX
{
    enum class SetDataOptions : ui32;

    class GraphicsDevice;

    class DynamicIndexBuffer : public IndexBuffer
    {
    public:
        DynamicIndexBuffer(YAX::IndexElementSize elemSize, i32 count, YAX::BufferUsage usage);
        DynamicIndexBuffer(const DynamicIndexBuffer&) = delete;
        DynamicIndexBuffer& operator=(const DynamicIndexBuffer&) = delete;
        DynamicIndexBuffer(DynamicIndexBuffer&&);
        DynamicIndexBuffer& operator=(DynamicIndexBuffer&&);
        ~DynamicIndexBuffer() = default;
    
        template<typename indexType>
        void SetData(i32 offsetInBytes, const std::vector<indexType>& src, i32 startIdx, i32 count, SetDataOptions option)
        {
            if (startIdx + count > src.size())
                throw std::invalid_argument("The vector is not the correct size for the amount of data requested.");

            if (count*sizeof(indexType) > (GLsizeiptr)_elemSize * _indCount)
                throw std::runtime_error("The buffer is not the correct size for the amount of data requested.");
            
            i32 isBound = 0;
            glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &isBound);
            if (isBound == _id)
                throw std::runtime_error("Cannot modify a buffer while it is in use.");

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER);
            if (option == SetDataOptions::Discard)
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)_elemSize * _indCount, nullptr, GL_STREAM_DRAW);

            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offsetInBytes, (GLsizeiptr)count * sizeof(indexType), &src[startIdx]);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
        
        template<typename indexType>
        void SetData(const std::vector<indexType>& src, i32 startIdx, i32 count, SetDataOptions option)
        {
            SetData(0, src, startIdx, count, option);
        }
        
    };
    
    
}


#endif
