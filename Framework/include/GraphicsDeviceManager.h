#ifndef _GRAPHICS_DEVICE_MANAGER_H
#define _GRAPHICS_DEVICE_MANAGER_H

#include <vector>
#include "Utils.h"

namespace XNA
{
	enum class GraphicsProfile;
	enum class DepthFormat;
	enum class SurfaceFormat;

	class Game;
	class GraphicsDevice;
	class GraphicsDeviceInformation;

	class GraphicsDeviceManager
	{
	public:
		GraphicsDeviceManager(Game&);

		static i32 DefaultBackBufferHeight();
		static i32 DefaultBackBufferWidth();

		XNA::GraphicsDevice GraphicsDevice();

		bool IsFullScreen();
		void IsFullScreen(bool);

		bool PreferMultiSampling();
		void PreferMultiSampling(bool);

		SurfaceFormat PreferredBackBufferFormat();
		void PreferredBackBufferFormat(SurfaceFormat);

		i32 PreferredBackBufferHeight();
		void PreferredBackBufferHeight(i32);

		i32 PreferredBackBufferWidth();
		void PreferredBackBufferWidth(i32);

		DepthFormat PreferredDepthStencilFormat();
		void PreferredDepthStencilFormat(DepthFormat);

		bool SyncronizeWithVerticalRetrace();
		void SyncronizeWithVerticalRetrace(bool); 

		void ApplyChanges();

		void ToggleFullScreen();

	protected:
		virtual bool CanResetDevice();
		virtual GraphicsDeviceInformation FindBestDevice();
		virtual void RankDevices(std::vector<GraphicsDeviceInformation>);

	private:
		static i32 _defaultBufWidth, _defaultBufHeight;

	};
}


#endif