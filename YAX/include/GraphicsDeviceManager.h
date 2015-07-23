#ifndef _GRAPHICS_DEVICE_MANAGER_H
#define _GRAPHICS_DEVICE_MANAGER_H

#include <memory>
#include <vector>
#include "IGraphicsDeviceManager.h"
#include "IGraphicsDeviceService.h"
#include "Utils.h"

namespace YAX
{
	enum class GraphicsProfile : ui32;
	enum class DepthFormat : ui32;
	enum class SurfaceFormat : ui32;

	class Game;

	class GraphicsDeviceManager : public IGraphicsDeviceManager, public IGraphicsDeviceService
	{
	public:
		GraphicsDeviceManager(Game*);
		~GraphicsDeviceManager();

		static i32 DefaultBackBufferHeight();
		static i32 DefaultBackBufferWidth();

		YAX::GraphicsProfile GraphicsProfile() const;
		void GraphicsProfile(YAX::GraphicsProfile);

		bool IsFullScreen() const;
		void IsFullScreen(bool);

		bool PreferMultiSampling() const;
		void PreferMultiSampling(bool);

		SurfaceFormat PreferredBackBufferFormat() const;
		void PreferredBackBufferFormat(SurfaceFormat);

		i32 PreferredBackBufferHeight() const;
		void PreferredBackBufferHeight(i32);

		i32 PreferredBackBufferWidth() const;
		void PreferredBackBufferWidth(i32);

		DepthFormat PreferredDepthStencilFormat() const;
		void PreferredDepthStencilFormat(DepthFormat);

		bool SyncronizeWithVerticalRetrace() const;
		void SyncronizeWithVerticalRetrace(bool); 

		void ApplyChanges();
		bool BeginDraw() override;
		void CreateDevice() override;
		void EndDraw() override;
		void ToggleFullScreen();

	/*protected: //Not implementing these until there is some demonstrable need
		virtual bool CanResetDevice();
		virtual GraphicsDeviceInformation FindBestDevice();
		virtual void RankDevices(std::vector<GraphicsDeviceInformation>);*/

	private:
		static const i32 _defaultBufWidth, _defaultBufHeight;

        Game* _game;
        YAX::GraphicsProfile _profile;
        SurfaceFormat _sFmt;
        DepthFormat _dFmt;
        bool _isFullScrn, _multiSampPref, _vSync;
        i32 _bufHeight, _bufWidth;
	};
}


#endif