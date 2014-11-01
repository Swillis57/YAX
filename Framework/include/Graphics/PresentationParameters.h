#ifndef _PRESENTATION_PARAMS_H
#define _PRESENTATION_PARAMS_H

#include "../Utils.h"
#include "../Geometry/Rectangle.h"

namespace XNA
{
	enum class DisplayOrientation;
	enum class PresentInterval;
	enum class SurfaceFormat;
	enum class DepthFormat;
	enum class RenderTargetUsage;

	class PresentationParameters
	{
	public:

		PresentationParameters();

		SurfaceFormat BackBufferFormat();
		void BackBufferFormat(SurfaceFormat);

		i32 BackBufferHeight();
		void BackBufferHeight(i32);

		i32 BackBufferWidth();
		void BackBufferWidth(i32);

		Rectangle Bounds();

		DepthFormat DepthStencilFormat();
		void DepthStencilFormat(DepthFormat);

		i32 DeviceWindowHandle();
		void DeviceWindowHandle(i32);

		XNA::DisplayOrientation DisplayOrientation();
		void DisplayOrientation(XNA::DisplayOrientation);

		bool IsFullScreen();
		void IsFullScreen(bool);

		i32 MultiSampleCount();
		void MultiSampleCount(i32);

		PresentInterval PresentationInterval();
		void PresentationInterval(PresentInterval);

		XNA::RenderTargetUsage RenderTargetUsage();
		void RenderTargetUsage(XNA::RenderTargetUsage);


	private:
		SurfaceFormat _backBufFormat;
		i32 _backBufHeight;
		i32 _backBufWidth;
		Rectangle _bounds;
		DepthFormat _depthFormat;
		i32 _winHandle;
		XNA::DisplayOrientation _displayOrientation;
		bool _fullScreen;
		i32 _sampleCount;
		PresentInterval _interval;
		XNA::RenderTargetUsage _targetUsage;

	};
	
}
#endif