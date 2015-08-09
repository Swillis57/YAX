#include "GraphicsDeviceManager.h"

#include <exception>
#include "Game.h"		
#include "GameServiceContainer.h"
#include "GameWindow.h"
#include "GraphicsDeviceInformation.h"
#include "Graphics/GraphicsAdapter.h"
#include "Graphics/DepthFormat.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/GraphicsProfile.h"
#include "Graphics/SurfaceFormat.h"
#include "Graphics/PresentInterval.h"

struct GLFWwindow;

namespace YAX
{
    const i32 GraphicsDeviceManager::_defaultBufHeight = 480;
    const i32 GraphicsDeviceManager::_defaultBufWidth = 800;

    GraphicsDeviceManager::GraphicsDeviceManager(Game* game)
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

        _game->Services()->AddService<IGraphicsDeviceService>(*this);
        _game->Services()->AddService<IGraphicsDeviceManager>(*this);
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
        return _profile;
    }

    void GraphicsDeviceManager::GraphicsProfile(YAX::GraphicsProfile profile)
    {
        _profile = profile;
    }

    bool GraphicsDeviceManager::IsFullScreen() const
    {
        return _isFullScrn;
    }

    void GraphicsDeviceManager::IsFullScreen(bool b)
    {
        _isFullScrn = b;
    }

    bool GraphicsDeviceManager::PreferMultiSampling() const
    {
        return _multiSampPref;
    }

    void GraphicsDeviceManager::PreferMultiSampling(bool b)
    {
        _multiSampPref = b;
    }

    SurfaceFormat GraphicsDeviceManager::PreferredBackBufferFormat() const
    {
        return _sFmt;
    }

    void GraphicsDeviceManager::PreferredBackBufferFormat(SurfaceFormat sf)
    {
        _sFmt = sf;
    }

    i32 GraphicsDeviceManager::PreferredBackBufferHeight() const
    {
        return _bufHeight;
    }

    void GraphicsDeviceManager::PreferredBackBufferHeight(i32 h)
    {
        _bufHeight = h;
    }

    i32 GraphicsDeviceManager::PreferredBackBufferWidth() const
    {
        return _bufWidth;
    }

    void GraphicsDeviceManager::PreferredBackBufferWidth(i32 w)
    {
        _bufWidth = w;
    }

    DepthFormat GraphicsDeviceManager::PreferredDepthStencilFormat() const
    {
        return _dFmt;
    }

    void GraphicsDeviceManager::PreferredDepthStencilFormat(DepthFormat df)
    {
        _dFmt = df;
    }

    bool GraphicsDeviceManager::SyncronizeWithVerticalRetrace() const
    {
        return _vSync;
    }

    void GraphicsDeviceManager::SyncronizeWithVerticalRetrace(bool b)
    {
        _vSync = b;
    }

    void GraphicsDeviceManager::ApplyChanges()
    {
        //Don't do anything if the graphics device hasn't been initialized yet
        if (!_graphicsDev) return;

        if (_isFullScrn && (_bufHeight == 0 || _bufWidth == 0))
            throw std::invalid_argument("Full-screen mode cannot be used if a dimension of the screen is zero");

        auto p = _graphicsDev->PresentationParameters();

        p.BackBufferHeight(_bufHeight);
        p.BackBufferWidth(_bufWidth);
        p.IsFullScreen(_isFullScrn);
        p.BackBufferFormat(_sFmt);
        p.DepthStencilFormat(_dFmt);
        //p->MultiSampleCount(4); //TODO: Multisampling

        if (_vSync)
            p.PresentationInterval(PresentInterval::One);


        _graphicsDev->Reset(p);
    }

    bool GraphicsDeviceManager::BeginDraw()
    {
        return (_graphicsDev && (_drawing = true));
    }

    void GraphicsDeviceManager::CreateDevice()
    {
        GraphicsAdapter::FindAdapters();

        auto pp = PresentationParameters();
        pp.DeviceWindowHandle(_game->Window()->Handle());

        //If events were implemented, there would be a call to
        //OnPreparingDeviceSettings here, as well as copying the user's changes
        //to the GDM

        _graphicsDev.reset(new YAX::GraphicsDevice(*GraphicsAdapter::DefaultAdapter(), _profile, pp));
        ApplyChanges();
    }

    void GraphicsDeviceManager::EndDraw()
    {
        if (_graphicsDev && _drawing)
        {
            _drawing = false;
            _graphicsDev->Present();
        }
    }

    void GraphicsDeviceManager::ToggleFullScreen()
    {
        _isFullScrn = !_isFullScrn;
        _graphicsDev->PresentationParameters().IsFullScreen(_isFullScrn);
        _graphicsDev->ApplyFullscreen(_game->Window());
    }

}

