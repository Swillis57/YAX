#include "../include/Game.h"

#include <chrono>
#include <thread>
#include <exception>
#include <iostream>
#include <cstdlib>
#include "../include/Graphics/GraphicsDevice.h"
#include "../../external/glew/include/GL/glew.h"
#include "../../external/glfw/include/GLFW/glfw3.h"
#include "../include/GameServiceContainer.h"
#include "../include/GameTime.h"
#include "../include/GameWindow.h"
#include "../include/GraphicsDeviceManager.h"
#include "../include/MathHelper.h"
#include "../include/Stopwatch.h"
#include "../include/TimeSpan.h"

namespace YAX
{
	struct Game::Impl
	{
		bool _isActive, _isFixedTimeStep, _isMouseVisible;
		bool _shouldRun, _shouldDraw, _running, _drawing;
		GameServiceContainer _services;
		GameTime _gameTime;
		IGraphicsDeviceService* _gdService;
		std::unique_ptr<GameWindow> _window;
		YAX::LaunchParameters _params;
		i64 _prevTime, _frameLag;
		Stopwatch _timer;
		TimeSpan _sleepTime, _targElapsedTime, _totalUpdateTime;

		Impl()
			: _sleepTime(TimeSpan::FromMilliseconds(20)),
			_targElapsedTime(TimeSpan::FromTicks(166667)),
			_totalUpdateTime(0),
			_gdService(nullptr),
			_prevTime(0),
			_frameLag(0)
		{
			_isActive = false;
			_isFixedTimeStep = true;
			_isMouseVisible = true;
			_shouldRun = true;
			_shouldDraw = true;
			_running = false;
			_drawing = false;
		}
	};

	Game::Game()
		: _impl(std::make_unique<Impl>())
	{}
	
	Game::~Game() = default;

	GameServiceContainer* Game::Services()
	{
		return &_impl->_services;
	}

	YAX::GraphicsDevice* Game::GraphicsDevice()
	{
		if (!_impl->_gdService)
			_impl->_gdService = (IGraphicsDeviceService*)_impl->_services.GetService<IGraphicsDeviceService>();
		return _impl->_gdService->GraphicsDevice();
	}

	TimeSpan Game::InactiveSleepTime()
	{
		return _impl->_sleepTime;
	}

	void Game::InactiveSleepTime(const TimeSpan& ts)
	{
		if (ts < TimeSpan::Zero)
			throw std::invalid_argument("The value of InactiveSleepTime must be greater than or equal to zero.");
		
		_impl->_sleepTime = ts;
	}

	bool Game::IsActive()
	{
		return _impl->_isActive;
	}

	void Game::IsActive(bool b)
	{
		_impl->_isActive = b;
	}

	bool Game::IsFixedTimeStep()
	{
		return _impl->_isFixedTimeStep;
	}

	void Game::IsFixedTimeStep(bool b)
	{
		_impl->_isFixedTimeStep = b;
	}

	bool Game::IsMouseVisible()
	{
		return _impl->_isMouseVisible;
	}

	void Game::IsMouseVisible(bool b)
	{
		_impl->_isMouseVisible = b;
	}

	YAX::LaunchParameters Game::LaunchParameters()
	{
		return _impl->_params;
	}

	TimeSpan Game::TargetElapsedTime()
	{
		return _impl->_targElapsedTime;
	}
	
	void Game::TargetElapsedTime(const TimeSpan& ts)
	{
		if (ts <= TimeSpan::Zero)
			throw std::invalid_argument("The value of TargetElapsedTime must be greater than zero.");
		
		_impl->_targElapsedTime = ts;
	}

	GameWindow* Game::Window()
	{
		return _impl->_window.get();
	}

	void Game::Exit()
	{
		glfwSetWindowShouldClose(_impl->_window->Handle(), 1);
		_impl->_shouldRun = false;
	}

	void Game::ResetElapsedTime()
	{
		_impl->_gameTime.ElapsedGameTime(TimeSpan::Zero);
	}

	void Game::Run()
	{
		Initialize();
		BeginRun();
		_impl->_timer.Start();

		while (_impl->_shouldRun)
		{
			Tick();
		}

		EndRun();
		UnloadContent();
		Exit();
	}

	void Game::RunOneFrame()
	{
		Initialize();
		BeginRun();
		_impl->_timer.Start();

		Tick();
		
		EndRun();
		UnloadContent();
		Exit();
	}

	void Game::SuppressDraw()
	{
		_impl->_shouldDraw = false;
	}

	void Game::Tick()
	{
		TimeSpan maxUpdateTime = TimeSpan::FromMilliseconds(500);
		
		//Based on FNA's Tick implementation
		i64 curTime = _impl->_timer.Elapsed().GetTicks();
		_impl->_totalUpdateTime += TimeSpan::FromTicks(curTime - _impl->_prevTime);
		_impl->_prevTime = curTime;

		//If the game is running in fixed-step mode, wait until the full TargetElapsedTime has passed
		if (_impl->_isFixedTimeStep)
		{
			while (_impl->_totalUpdateTime < _impl->_targElapsedTime)
			{
				i32 sleepTime = (i32)(_impl->_targElapsedTime - _impl->_totalUpdateTime).GetTotalMilliseconds();

				std::this_thread::sleep_for((milliseconds)sleepTime);

				curTime = _impl->_timer.Elapsed().GetTicks();
				_impl->_totalUpdateTime += TimeSpan::FromTicks(curTime - _impl->_prevTime);
				_impl->_prevTime = curTime;
			}
		}

		//Don't update for longer than maxUpdateTime
		if (_impl->_totalUpdateTime > maxUpdateTime)
		{
			_impl->_totalUpdateTime = maxUpdateTime;
		}

		//While we haven't hit the next update mark, call Update as many times as possible
		if (_impl->_isFixedTimeStep)
		{
			_impl->_gameTime.ElapsedGameTime(_impl->_targElapsedTime);
			i32 steps = 0;

			while (_impl->_totalUpdateTime >= _impl->_targElapsedTime)
			{
				_impl->_gameTime.TotalGameTime() += _impl->_targElapsedTime;
				_impl->_totalUpdateTime -= _impl->_targElapsedTime;
				steps++;

				Update(_impl->_gameTime);
			}

			//If Update was called more than once per frame, then the game is running slow
			_impl->_frameLag += (i32)MathHelper::Max(0, (float)(steps - 1));

			//If the lag has passed, turn the RunningSlow flag off
			//else if the number of frames that have lagged > 5, turn the flag on
			if (_impl->_gameTime.IsRunningSlow())
			{
				if (_impl->_frameLag == 0)
				{
					_impl->_gameTime.IsRunningSlow(false);
				}
			}
			else if (_impl->_frameLag >= 5)
			{
				_impl->_gameTime.IsRunningSlow(true);
			}

			if (steps == 1 && _impl->_frameLag > 0)
			{
				_impl->_frameLag -= 1;
			}

			_impl->_gameTime.ElapsedGameTime(TimeSpan::FromTicks(_impl->_targElapsedTime.GetTicks() * steps));
		}
		else
		{
			//Not fixed-step mode, just update the total time and call update
			_impl->_gameTime.ElapsedGameTime(_impl->_totalUpdateTime);
			_impl->_gameTime.TotalGameTime() += _impl->_totalUpdateTime;
			_impl->_totalUpdateTime = TimeSpan::Zero;

			Update(_impl->_gameTime);
		}

		if (!_impl->_shouldDraw)
		{
			_impl->_shouldDraw = true;
		}
		else 
		{
			BeginDraw();
			Draw();
			EndDraw();
		}

	}

	bool Game::BeginDraw()
	{
		return (_impl->_drawing = true);
	}

	void Game::BeginRun()
	{
		_impl->_running = true;
	}

	void Game::Draw()
	{}

	void Game::EndDraw()
	{
		_impl->_gdService->GraphicsDevice()->Present();
		_impl->_drawing = false;
	}

	void Game::EndRun()
	{
		_impl->_running = false;
	}

	void Game::Initialize()
	{
		if (!glfwInit())
		{
			std::cout << "Error initializing GLFW" << std::endl;
			std::cin.get();
			std::exit(EXIT_FAILURE);
		}

		glewExperimental = true;
		if (!glewInit())
		{
			std::cout << "Error initializing GLEW" << std::endl;
			std::cin.get();
			std::exit(EXIT_FAILURE);
		}

		_impl->_window = std::unique_ptr<GameWindow>(new GameWindow(
			"",
			GraphicsDeviceManager::DefaultBackBufferWidth(),
			GraphicsDeviceManager::DefaultBackBufferHeight()
			));

		_impl->_gdService = (IGraphicsDeviceService*)_impl->_services.GetService<IGraphicsDeviceService>();

		if (_impl->_gdService && _impl->_gdService->GraphicsDevice())
		{
			LoadContent();
		}
	}

	void Game::LoadContent()
	{
		//Content Pipeline NYI
	}

	void Game::UnloadContent()
	{

	}

	void Game::Update(const GameTime& gt)
	{
		//Not using GameComponents, so the base Update does nothing	
	}
}