#ifndef _PRESENTATION_PARAMS_H
#define _PRESENTATION_PARAMS_H

#include "../GLFW/glfw3.h"
#include "../Utils.h"

namespace XNA
{
	enum class DisplayOrientation : int;
	enum class PresentInterval : int;
	enum class SurfaceFormat : int;
	enum class DepthFormat : int;
	enum class RenderTargetUsage : int;

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

		XNA::RenderTargetUsage RenderTargetUsage() const;
		void RenderTargetUsage(XNA::RenderTargetUsage);


	private:
		SurfaceFormat _backBufFormat;
		i32 _backBufHeight, _backBufWidth;
		DepthFormat _depthFormat;
		GLFWwindow* _winHandle;
		bool _fullScreen;
		i32 _sampleCount;
		PresentInterval _interval;
		XNA::RenderTargetUsage _targetUsage;

	};
	
}
#endif