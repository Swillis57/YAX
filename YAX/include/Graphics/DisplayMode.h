#ifndef _DISPLAY_MODE_H
#define _DISPLAY_MODE_H

#include <memory>
#include "Rectangle.h"
#include "../Utils.h"

namespace YAX
{
    struct Rectangle;
    
    //DisplayMode is only used to describe monitors
    //and GLFW specifies bit depths separately
    struct DisplayFormat
    {
        i32 R, G, B;
    };

    class DisplayMode
    {
    public:
        DisplayMode(DisplayFormat format, Rectangle screenArea);

        float AspectRatio() const;

        DisplayFormat Format() const;

        i32 Height() const;

        Rectangle TitleSafeArea() const;

        i32 Width() const;

    private:
        float _aspectRatio;
        DisplayFormat _format;
        Rectangle _area;

    };
}

#endif