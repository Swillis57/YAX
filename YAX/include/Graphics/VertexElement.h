#ifndef _VERTEX_ELEMENT_H
#define _VERTEX_ELEMENT_H

#include "../Utils.h"

namespace YAX
{
    enum class VertexElementFormat : ui32;
    enum class VertexElementUsage : ui32;

    struct VertexElement
    {
    public:
        VertexElement(i32 offset, YAX::VertexElementFormat fmt, YAX::VertexElementUsage usage, i32 usageIdx);

        i32 Offset() const;
        void Offset(i32);

        i32 UsageIndex() const;
        void UsageIndex(i32);
        
        YAX::VertexElementFormat VertexElementFormat() const;
        void VertexElementFormat(YAX::VertexElementFormat);

        YAX::VertexElementUsage VertexElementUsage() const;
        void VertexElementUsage(YAX::VertexElementUsage);
    
        friend bool operator==(const VertexElement&, const VertexElement&);
        friend bool operator!=(const VertexElement&, const VertexElement&);

    private:
        i32 _offset, _usageIdx;
        YAX::VertexElementFormat _fmt;
        YAX::VertexElementUsage _usg;
    };
}


#endif