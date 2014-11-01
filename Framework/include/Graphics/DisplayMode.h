#ifndef _DISPLAY_MODE_H
#define _DISPLAY_MODE_H

#include "../Utils.h"
#include "../Geometry/Rectangle.h"

namespace XNA
{
	enum class SurfaceFormat;

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
		float _aspectRatio;
		SurfaceFormat _format;
		i32 _height;
		Rectangle _titleSafeArea;
		i32 _width;

	};
}

#endif