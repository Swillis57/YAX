#include "../../include/Graphics/PresentationParameters.h"

#include "../../include/Graphics/PresentInterval.h"
#include "../../include/Graphics/SurfaceFormat.h"
#include "../../include/Graphics/DepthFormat.h"
#include "../../include/Graphics/RenderTargetUsage.h"
#include "../../include/Rectangle.h"

namespace YAX
{
	PresentationParameters::PresentationParameters()
		: _backBufFormat(SurfaceFormat::Color),
		_backBufHeight(0),
		_backBufWidth(0),
		_depthFormat(DepthFormat::None),
		_winHandle(nullptr),
		_fullScreen(true),
		_sampleCount(0),
		_interval(PresentInterval::Default),
		_targetUsage(YAX::RenderTargetUsage::DiscardContents)
	{}

	SurfaceFormat PresentationParameters::BackBufferFormat() const
	{
		return _backBufFormat;
	}

	void PresentationParameters::BackBufferFormat(SurfaceFormat sf)
	{
		_backBufFormat = sf;
	}

	i32 PresentationParameters::BackBufferHeight() const
	{
		return _backBufHeight;
	}

	void PresentationParameters::BackBufferHeight(i32 h)
	{
		_backBufHeight = h;
	}

	i32 PresentationParameters::BackBufferWidth() const
	{
		return _backBufWidth;
	}

	void PresentationParameters::BackBufferWidth(i32 w)
	{
		_backBufWidth = w;
	}

	Rectangle PresentationParameters::Bounds() const
	{
		return Rectangle(0, 0, _backBufWidth, _backBufHeight);
	}

	DepthFormat PresentationParameters::DepthStencilFormat() const
	{
		return _depthFormat;
	}

	void PresentationParameters::DepthStencilFormat(DepthFormat df)
	{
		_depthFormat = df;
	}

	GLFWwindow* PresentationParameters::DeviceWindowHandle() const
	{
		return _winHandle;
	}

	void PresentationParameters::DeviceWindowHandle(GLFWwindow* hnd)
	{
		_winHandle = hnd;
	}

	bool PresentationParameters::IsFullScreen() const
	{
		return _fullScreen;
	}

	void PresentationParameters::IsFullScreen(bool b)
	{
		_fullScreen = b;
	}

	i32 PresentationParameters::MultiSampleCount() const
	{
		return _sampleCount;
	}

	void PresentationParameters::MultiSampleCount(i32 count)
	{
		_sampleCount = count;
	}

	PresentInterval PresentationParameters::PresentationInterval() const
	{
		return _interval;
	}

	void PresentationParameters::PresentationInterval(PresentInterval pi)
	{
		_interval = pi;
	}

	YAX::RenderTargetUsage PresentationParameters::RenderTargetUsage() const
	{
		return _targetUsage;
	}

	void PresentationParameters::RenderTargetUsage(YAX::RenderTargetUsage rtu)
	{
		_targetUsage = rtu;
	}
}