#include "../include/GraphicsDeviceManager.h"

#include <exception>
#include "../include/Game.h"		
#include "../include/GameServiceContainer.h"
#include "../include/GameWindow.h"
#include "../include/GraphicsDeviceInformation.h"
#include "../include/Graphics/GraphicsAdapter.h"
#include "../include/Graphics/DepthFormat.h"
#include "../include/Graphics/GraphicsDevice.h"
#include "../include/Graphics/GraphicsProfile.h"
#include "../include/Graphics/SurfaceFormat.h"
#include "../include/Graphics/PresentInterval.h"
#include "../../external/glfw/include/GLFW/glfw3.h"

namespace YAX
{
	const i32 GraphicsDeviceManager::_defaultBufHeight = 480;
	const i32 GraphicsDeviceManager::_defaultBufWidth = 800;

	struct GraphicsDeviceManager::Impl
	{
		Game* _game;
		std::shared_ptr<YAX::GraphicsDevice> _graphicsDev = nullptr;
		YAX::GraphicsProfile _profile;
		SurfaceFormat _sFmt;
		DepthFormat _dFmt;
		bool _isFullScrn, _multiSampPref, _vSync, _drawing;
		i32 _bufHeight, _bufWidth;

		Impl(Game* game, std::shared_ptr<YAX::GraphicsDevice> device)
		{
			_game = game;
			_profile = YAX::GraphicsProfile::HiDef;
			_sFmt = SurfaceFormat::Color;
			_dFmt = DepthFormat::Depth24;
			_isFullScrn = false;
			_multiSampPref = false;
			_vSync = true;
			_bufHeight = GraphicsDeviceManager::_defaultBufHeight;
			_bufWidth = GraphicsDeviceManager::_defaultBufWidth;
			_graphicsDev = device;
		}

		void applyChanges()
		{
			//Don't do anything if the graphics device hasn't been initialized yet
			if (!_graphicsDev) return;

			if (_isFullScrn && (_bufHeight == 0 || _bufWidth == 0)) 
				throw std::invalid_argument("Full-screen mode cannot be used if a dimension of the screen is zero");
			
			PresentationParameters& p = _graphicsDev->PresentationParameters();

			p.BackBufferHeight(_bufHeight);
			p.BackBufferWidth(_bufWidth);
			p.IsFullScreen(_isFullScrn);
			p.BackBufferFormat(_sFmt);
			p.DepthStencilFormat(_dFmt);
			
			if (_vSync)
				p.PresentationInterval(PresentInterval::One);

			
			_graphicsDev->Reset();
		}

		void createDevice()
		{
			GraphicsDeviceInformation info;
			info.Adapter = GraphicsAdapter::DefaultAdapter();
			info.GraphicsProfile = _profile;
			info.PresentationParameters.DeviceWindowHandle(_game->Window()->Handle());

			//If events were implemented, there would be a call to
			//OnPreparingDeviceSettings here, as well as copying the user's changes
			//to the GDM

			*_graphicsDev = YAX::GraphicsDevice(info.Adapter, info.GraphicsProfile, info.PresentationParameters);
			applyChanges();
		}

		bool beginDraw()
		{
			if (_graphicsDev)
				return (_drawing = true);
			return false;
		}

		void endDraw()
		{
			if (_graphicsDev && _drawing)
			{
				_drawing = false;
				_graphicsDev->Present();
			}	
		}

		void toggleFullScreen()
		{
			_isFullScrn = !_isFullScrn;
			_graphicsDev->PresentationParameters().IsFullScreen(_isFullScrn);
			_graphicsDev->applyFullscreen();
		}
	};

	GraphicsDeviceManager::GraphicsDeviceManager(Game* game)
		: _impl(std::make_unique<Impl>(game, _graphicsDev))
	{
		game->Services()->AddService<IGraphicsDeviceService>(*this);
		game->Services()->AddService<IGraphicsDeviceManager>(*this);
	}

	GraphicsDeviceManager::~GraphicsDeviceManager() = default;

	i32 GraphicsDeviceManager::DefaultBackBufferWidth()
	{
		return GraphicsDeviceManager::_defaultBufWidth;
	}

	i32 GraphicsDeviceManager::DefaultBackBufferHeight()
	{
		return GraphicsDeviceManager::_defaultBufHeight;
	}

	YAX::GraphicsProfile GraphicsDeviceManager::GraphicsProfile() const
	{
		return _impl->_profile;
	}

	void GraphicsDeviceManager::GraphicsProfile(YAX::GraphicsProfile profile)
	{
		_impl->_profile = profile;
	}

	bool GraphicsDeviceManager::IsFullScreen() const
	{
		return _impl->_isFullScrn;
	}

	void GraphicsDeviceManager::IsFullScreen(bool b)
	{
		_impl->_isFullScrn = b;
	}

	bool GraphicsDeviceManager::PreferMultiSampling() const
	{
		return _impl->_multiSampPref;
	}

	void GraphicsDeviceManager::PreferMultiSampling(bool b)
	{
		_impl->_multiSampPref = b;
	}

	SurfaceFormat GraphicsDeviceManager::PreferredBackBufferFormat() const
	{
		return _impl->_sFmt;
	}

	void GraphicsDeviceManager::PreferredBackBufferFormat(SurfaceFormat sf)
	{
		_impl->_sFmt = sf;
	}

	i32 GraphicsDeviceManager::PreferredBackBufferHeight() const
	{
		return _impl->_bufHeight;
	}

	void GraphicsDeviceManager::PreferredBackBufferHeight(i32 h)
	{
		_impl->_bufHeight = h;
	}

	i32 GraphicsDeviceManager::PreferredBackBufferWidth() const
	{
		return _impl->_bufWidth;
	}

	void GraphicsDeviceManager::PreferredBackBufferWidth(i32 w)
	{
		_impl->_bufWidth = w;
	}

	DepthFormat GraphicsDeviceManager::PreferredDepthStencilFormat() const
	{
		return _impl->_dFmt;
	}

	void GraphicsDeviceManager::PreferredDepthStencilFormat(DepthFormat df)
	{
		_impl->_dFmt = df;
	}

	bool GraphicsDeviceManager::SyncronizeWithVerticalRetrace() const
	{
		return _impl->_vSync;
	}

	void GraphicsDeviceManager::SyncronizeWithVerticalRetrace(bool b)
	{
		_impl->_vSync = b;
	}

	void GraphicsDeviceManager::ApplyChanges()
	{
		_impl->applyChanges();
	}

	bool GraphicsDeviceManager::BeginDraw()
	{
		return _impl->beginDraw();
	}

	void GraphicsDeviceManager::CreateDevice()
	{
		_impl->createDevice();
	}

	void GraphicsDeviceManager::EndDraw()
	{
		_impl->endDraw();
	}

	void GraphicsDeviceManager::ToggleFullScreen()
	{
		_impl->toggleFullScreen();
	}

}

