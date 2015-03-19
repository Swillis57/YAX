#include "../include/GraphicsDeviceManager.h"

#include "../include/Game.h"
#include "../../YAX.Graphics/include/DepthFormat.h"
#include "../../YAX.Graphics/include/GraphicsDevice.h"
#include "../../YAX.Graphics/include/GraphicsProfile.h"
#include "../../YAX.Graphics/include/SurfaceFormat.h"

namespace YAX
{
	const i32 GraphicsDeviceManager::_defaultBufHeight = 480;
	const i32 GraphicsDeviceManager::_defaultBufWidth = 800;

	struct GraphicsDeviceManager::Impl
	{
		Game* _game;
		YAX::GraphicsDevice* _graphicsDev;
		SurfaceFormat _sFmt;
		DepthFormat _dFmt;
		bool _isFullScrn, _multiSampPref, _vSync;
		i32 _bufHeight, _bufWidth;

		Impl(Game& game)
		{
			_game = &game;
			_graphicsDev = nullptr;
			_sFmt = SurfaceFormat::Color;
			_dFmt = DepthFormat::Depth24;
			_isFullScrn = false;
			_multiSampPref = false;
			_vSync = true;
			_bufHeight = GraphicsDeviceManager::_defaultBufHeight;
			_bufWidth = GraphicsDeviceManager::_defaultBufWidth;
		}
	};		
}

