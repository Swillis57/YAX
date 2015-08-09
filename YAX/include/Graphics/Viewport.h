#ifndef _VIEWPORT_H
#define _VIEWPORT_H

#include "../Rectangle.h"
#include "../Utils.h"

namespace YAX
{
    struct Rectangle;
    struct Vector3;
    struct Matrix;

    struct Viewport
    {
    public:
        Viewport(i32 x, i32 y, i32 w, i32 h);
        Viewport(const Rectangle&);

        float AspectRatio() const;

        Rectangle Bounds() const;
        void Bounds(const Rectangle&);

        i32 Height() const;
        void Height(i32);

        float MaxDepth() const;
        void MaxDepth(float);

        float MinDepth() const;
        void MinDepth(float);

        Rectangle TitleSafeArea() const;

        i32 Width() const;
        void Width(i32);

        i32 X() const;
        void X(i32);

        i32 Y() const;
        void Y(i32);

        Vector3 Project(const Vector3& source, const Matrix& proj, const Matrix& view, const Matrix& world) const;
        Vector3 Unproject(const Vector3& source, const Matrix& proj, const Matrix& view, const Matrix& world) const;
    
        friend bool operator==(const Viewport&, const Viewport&);
        friend bool operator!=(const Viewport&, const Viewport&);
    
    private:
        float _minDepth, _maxDepth;
        Rectangle _dim;
    };

}


#endif                                                                       