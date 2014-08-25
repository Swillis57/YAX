#ifndef DISPLAY_MODE
#define DISPLAY_MODE

#include "../Utils.h"
#include "../Geometry/Rectangle.h"

namespace XNA
{
	class Rectangle;
    enum SurfaceFormat;

	class DisplayMode
	{
	public:
		float AspectRatio();
		SurfaceFormat Format();
		i32 Height();
		Rectangle TitleSafeArea();
		i32 Width();

		DisplayMode(SurfaceFormat, Rectangle, i32, i32);
	private:
		float aspectRatio;
		SurfaceFormat format;
		i32 height;
		Rectangle titleSafeArea;
		i32 width;

	};

	DisplayMode::DisplayMode(SurfaceFormat sf, Rectangle rect, i32 h, i32 w)
		: format(sf), titleSafeArea(rect), height(h), width(w), aspectRatio((float)h / w)
	{}
}

#endif