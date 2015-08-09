#include "Graphics/DisplayMode.h"
#include "Rectangle.h"

namespace YAX
{
    DisplayMode::DisplayMode(DisplayFormat format, Rectangle rect)
        : _aspectRatio(rect.Height() / rect.Width()),
        _format(format),
        _area(rect)
    {}

    float DisplayMode::AspectRatio() const
    {
        return _aspectRatio;
    }

    DisplayFormat DisplayMode::Format() const
    {
        return _format;
    }

    i32 DisplayMode::Height() const
    {
        return _area.Height();
    }

    Rectangle DisplayMode::TitleSafeArea() const
    {
        i32 newX = _area.Width() * 0.1f;
        i32 newY = _area.Height() * 0.1f;
        return Rectangle(newX, newY, _area.Width() - newX, _area.Height() - newY);
    }

    i32 DisplayMode::Width() const
    {
        return _area.Width();
    }







}