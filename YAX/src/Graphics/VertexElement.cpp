#include "Graphics/VertexElement.h"

#include "Graphics/VertexElementFormat.h"
#include "Graphics/VertexElementUsage.h"

namespace YAX
{
    VertexElement::VertexElement(i32 offset, YAX::VertexElementFormat fmt, YAX::VertexElementUsage usage, i32 usageIdx)
        : _offset(offset),
        _fmt(fmt),
        _usg(usage),
        _usageIdx(usageIdx)
    {}

    i32 VertexElement::Offset() const
    {
        return _offset;
    }

    void VertexElement::Offset(i32 offset)
    {
        _offset = offset;
    }

    i32 VertexElement::UsageIndex() const
    {
        return _usageIdx;
    }

    void VertexElement::UsageIndex(i32 uidx)
    {
        _usageIdx = uidx;
    }

    YAX::VertexElementFormat VertexElement::VertexElementFormat() const
    {
        return _fmt;
    }

    void VertexElement::VertexElementFormat(YAX::VertexElementFormat fmt)
    {
        _fmt = fmt;
    }

    YAX::VertexElementUsage VertexElement::VertexElementUsage() const
    {
        return _usg;
    }

    void VertexElement::VertexElementUsage(YAX::VertexElementUsage usg)
    {
        _usg = usg;
    }

    bool operator==(const VertexElement& lhs, const VertexElement& rhs)
    {
        return (lhs._offset == rhs._offset
            && lhs._usageIdx == rhs._usageIdx
            && lhs._fmt == rhs._fmt
            && lhs._usg == rhs._usg);
    }

    bool operator!=(const VertexElement& lhs, const VertexElement& rhs)
    {
        return !(lhs == rhs);
    }
}