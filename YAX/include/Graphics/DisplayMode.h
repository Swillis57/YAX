#ifndef _DISPLAY_MODE_H
#define _DISPLAY_MODE_H

#include <memory>
#include "../Utils.h"

namespace YAX
{
	struct GLFWvidmode;
	struct Rectangle;
	
	//DisplayMode is only used to describe monitors
	//and GLFW specifies bit depths separately
	struct DisplayFormat
	{
		i32 R, G, B;
	};

	class DisplayMode
	{
		struct Impl;

	public:
		DisplayMode(DisplayFormat format, Rectangle screenArea);
		DisplayMode(const DisplayMode&);
		DisplayMode& operator=(const DisplayMode&);
		~DisplayMode();

		float AspectRatio() const;

		DisplayFormat Format() const;

		i32 Height() const;

		Rectangle TitleSafeArea() const;

		i32 Width() const;

	private:
		std::unique_ptr<Impl> _impl;

	};
}

#endif