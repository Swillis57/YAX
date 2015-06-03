#ifndef _GAME_H
#define _GAME_H

#include <memory>
#include "LaunchParameters.h"

namespace YAX
{
	//class ContentManager;
	class GameServiceContainer;
	class GraphicsDevice;
	class GameTime;
	class GameWindow;
	struct TimeSpan;

	class Game
	{
		struct Impl;

	public:
		Game();
		~Game();

		/* Content Pipeline NYI
		ContentManager& Content();
		void Content(const ContentManager&);*/
		
		GameServiceContainer* Services();

		YAX::GraphicsDevice* GraphicsDevice();

		TimeSpan InactiveSleepTime();
		void InactiveSleepTime(const TimeSpan&);

		bool IsActive();
		void IsActive(bool);

		bool IsFixedTimeStep();
		void IsFixedTimeStep(bool);

		bool IsMouseVisible();
		void IsMouseVisible(bool);

		YAX::LaunchParameters LaunchParameters();

		TimeSpan TargetElapsedTime();
		void TargetElapsedTime(const TimeSpan&);

		GameWindow* Window();

		void Exit();
		void ResetElapsedTime();
		void Run();
		void RunOneFrame();
		void SuppressDraw();
		void Tick();

	protected:
		virtual bool BeginDraw();
		virtual void BeginRun();
		virtual void Draw();
		virtual void EndDraw();
		virtual void EndRun();
		virtual void Initialize();
		virtual void LoadContent();
		virtual void UnloadContent();
		virtual void Update(const GameTime&);

	private:
		std::unique_ptr<Impl> _impl;
	};
}
#endif