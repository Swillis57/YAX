#ifndef _DISPLAY_MODE_H
#define _DISPLAY_MODE_H

#include "../Geometry/Rectangle.h"
#include "../Utils.h"

namespace XNA
{
	enum class SurfaceFormat : int;

	class DisplayMode
	{
	public:
		DisplayMode(SurfaceFormat, Rectangle);
		DisplayMode(const DisplayMode&);
		DisplayMode& operator=(const DisplayMode&);

		float AspectRatio() const;

		SurfaceFormat Format() const;

		i32 Height() const;

		Rectangle TitleSafeArea() const;

		i32 Width() const;

	private:
		float _aspectRatio;
		SurfaceFormat _format;
		Rectangle _area;

	};
}

#endif