#ifndef _DISPLAY_MODE_H
#define _DISPLAY_MODE_H

#include "../Utils.h"
#include "../Geometry/Rectangle.h"

namespace XNA
{
	enum SurfaceFormat : short;

	class DisplayMode
	{
	public:
		float AspectRatio();
		SurfaceFormat Format();
		i32 Height();
		Rectangle* const TitleSafeArea();
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