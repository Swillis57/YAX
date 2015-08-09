#include "Graphics/Viewport.h"

#include "Matrix.h"
#include "MathHelper.h"
#include "Vector3.h"
#include "Vector4.h"

namespace YAX
{
    Viewport::Viewport(i32 x, i32 y, i32 w, i32 h)
        : _dim(x, y, w, h)
    {}

    Viewport::Viewport(const Rectangle& rect)
        : _dim(rect)
    {}

    float Viewport::AspectRatio() const
    {
        return (_dim.Width() > 0 && _dim.Height() > 0 
            ? (float)_dim.Width() / _dim.Height()
            : 0.0f);
    }

    Rectangle Viewport::Bounds() const
    {
        return _dim;
    }

    void Viewport::Bounds(const Rectangle& rect)
    {
        _dim = rect;
    }

    i32 Viewport::Height() const
    {
        return _dim.Height();
    }

    void Viewport::Height(i32 h)
    {
        _dim.Height(h);
    }

    float Viewport::MaxDepth() const
    {
        return _maxDepth;
    }

    void Viewport::MaxDepth(float f)
    {
        _maxDepth = f;
    }

    float Viewport::MinDepth() const
    {
        return _minDepth;
    }
    
    void Viewport::MinDepth(float f)
    {
        _minDepth = f;
    }

    Rectangle Viewport::TitleSafeArea() const
    {
        return _dim;
    }

    i32 Viewport::Width() const
    {
        return _dim.Width();
    }

    void Viewport::Width(i32 w)
    {
        _dim.Width(w);
    }

    i32 Viewport::X() const
    {
        return _dim.X();
    }

    void Viewport::X(i32 x)
    {
        _dim.X(x);
    }

    i32 Viewport::Y() const
    {
        return _dim.Y();
    }

    void Viewport::Y(i32 y)
    {
        _dim.Y(y);
    }

    Vector3 Viewport::Project(const Vector3& source, const Matrix& proj, const Matrix& view, const Matrix& world) const
    {
        //Make source a Vector4 so everything gets calculated in the transform
        Vector4 v { source, 1.0f };

        //Transform the vector
        Vector4::Transform(v, world*view*proj);

        //Do the perspective divide if needed
        if (std::fabsf(v.W - 1.0f) < MathHelper::Epsilon)
        {
            v.X /= v.W;
            v.Y /= v.W;
            v.Z /= v.W;
        }

        //Scale the vector by the viewport dimensions
        v.X = ((v.X + 1.0f)*0.5f * _dim.Width()) + _dim.X();
        v.Y = ((1.0f - v.Y)*0.5f * _dim.Height()) + _dim.Y();
        v.Z = (v.Z * (_maxDepth - _minDepth)) + _minDepth;

        return Vector3(v.X, v.Y, v.Z);
    }

    Vector3 Viewport::Unproject(const Vector3& source, const Matrix& proj, const Matrix& view, const Matrix& world) const
    {
        Vector4 v { source, 1.0f };

        v.X = ((v.X - _dim.X()) / (0.5f * _dim.Width())) - 1.0f;
        v.Y = -(((v.Y - _dim.Y()) / (0.5f * _dim.Height())) - 1.0f);
        v.Z = (v.Z - _minDepth) / (_maxDepth - _minDepth);
        Vector4::Transform(v, Matrix::Invert(world*view*proj));

        if (std::fabsf(v.W - 1.0f) < MathHelper::Epsilon)
        {
            v.X /= v.W;
            v.Y /= v.W;
            v.Z /= v.W;
        }

        return Vector3(v.X, v.Y, v.Z);
    }

    bool operator==(const Viewport& lhs, const Viewport& rhs)
    {
        return (lhs._dim == rhs._dim 
                && lhs._minDepth == rhs._minDepth
                && lhs._maxDepth == rhs._maxDepth);
    }

    bool operator!=(const Viewport& lhs, const Viewport& rhs)
    {
        return !(lhs == rhs);
    }
}