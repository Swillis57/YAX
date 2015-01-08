#include "../../include/Graphics/DisplayMode.h"
#include "../../include/Geometry/Rectangle.h"

namespace YAX
{
	struct DisplayMode::Impl
	{
		float _aspectRatio;
		DisplayFormat _format;
		Rectangle _area;

		Impl(DisplayFormat fmt, Rectangle rect)
			: _format(fmt), _area(rect),
			_aspectRatio(rect.Height() / rect.Width())
		{}

		Impl(const Impl& old)
			: _aspectRatio(old._aspectRatio), _format(old._format),
			_area(old._area)
		{}

		~Impl() = default;

		float AspectRatio() const
		{
			return _aspectRatio;
		}

		DisplayFormat Format() const
		{
			return _format;
		}

		i32 Height() const
		{
			return _area.Height();
		}

		Rectangle TitleSafeArea() const
		{
			i32 newX = _area.Width() * 0.1f;
			i32 newY = _area.Height() * 0.1f;
			return Rectangle(newX, newY, _area.Width() - newX, _area.Height() - newY);
		}

		i32 Width() const
		{
			return _area.Width();
		}
	};

	DisplayMode::DisplayMode(DisplayFormat format, Rectangle rect)
	{
		_impl = std::make_unique<Impl>(format, rect);
	}

	DisplayMode::DisplayMode(const DisplayMode& old)
	{
		_impl = std::make_unique<Impl>(*old._impl);
	}

	DisplayMode& DisplayMode::operator=(const DisplayMode& old)
	{
		this->_impl = std::make_unique<Impl>(*old._impl);
		return *this;
	}

	DisplayMode::~DisplayMode() = default;

	float DisplayMode::AspectRatio() const
	{
		return _impl->AspectRatio();
	}

	DisplayFormat DisplayMode::Format() const
	{
		return _impl->Format();
	}

	i32 DisplayMode::Height() const
	{
		return _impl->Height();
	}

	Rectangle DisplayMode::TitleSafeArea() const
	{
		return _impl->TitleSafeArea();
	}

	i32 DisplayMode::Width() const
	{
		return _impl->Width();
	}







}