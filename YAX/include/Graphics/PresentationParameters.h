#ifndef _PRESENTATION_PARAMS_H
#define _PRESENTATION_PARAMS_H

#include "../Utils.h"

struct GLFWwindow;

namespace YAX
{
	enum class PresentInterval : ui32;
	enum class SurfaceFormat : ui32;
	enum class DepthFormat : ui32;
	enum class RenderTargetUsage : ui32;

	struct Rectangle;

	class PresentationParameters
	{
	public:

		PresentationParameters();

		SurfaceFormat BackBufferFormat() const;
		void BackBufferFormat(SurfaceFormat);

		i32 BackBufferHeight() const;
		void BackBufferHeight(i32);

		i32 BackBufferWidth() const;
		void BackBufferWidth(i32);

		Rectangle Bounds() const;

		DepthFormat DepthStencilFormat() const;
		void DepthStencilFormat(DepthFormat);

		GLFWwindow* DeviceWindowHandle() const;
		void DeviceWindowHandle(GLFWwindow*);

		bool IsFullScreen() const;
		void IsFullScreen(bool);

		i32 MultiSampleCount() const;
		void MultiSampleCount(i32);

		PresentInterval PresentationInterval() const;
		void PresentationInterval(PresentInterval);

		YAX::RenderTargetUsage RenderTargetUsage() const;
		void RenderTargetUsage(YAX::RenderTargetUsage);


	private:
		SurfaceFormat _backBufFormat;
		i32 _backBufHeight, _backBufWidth;
		DepthFormat _depthFormat;
		GLFWwindow* _winHandle;
		bool _fullScreen;
		i32 _sampleCount;
		PresentInterval _interval;
		YAX::RenderTargetUsage _targetUsage;

	};
	
}
#endif