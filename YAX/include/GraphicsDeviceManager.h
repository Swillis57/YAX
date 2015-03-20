#ifndef _GRAPHICS_DEVICE_MANAGER_H
#define _GRAPHICS_DEVICE_MANAGER_H

#include <memory>
#include <vector>
#include "IGraphicsDeviceManager.h"
#include "IGraphicsDeviceService.h"
#include "Utils.h"

namespace YAX
{
	enum class GraphicsProfile : int;
	enum class DepthFormat : int;
	enum class SurfaceFormat : int;

	class Game;
	class GraphicsDevice;
	class GraphicsDeviceInformation;

	class GraphicsDeviceManager : public IGraphicsDeviceManager, public IGraphicsDeviceService
	{
		struct Impl;

	public:
		GraphicsDeviceManager(Game&);

		static i32 DefaultBackBufferHeight();
		static i32 DefaultBackBufferWidth();

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
		bool BeginDraw() override;
		void CreateDevice() override;
		void EndDraw() override;
		void ToggleFullScreen();

	protected:
		virtual bool CanResetDevice();
		virtual GraphicsDeviceInformation FindBestDevice();
		virtual void RankDevices(std::vector<GraphicsDeviceInformation>);

	private:
		static const i32 _defaultBufWidth, _defaultBufHeight;
		std::unique_ptr<Impl> _impl;

	};
}


#endif