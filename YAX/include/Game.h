#ifndef _GAME_H
#define _GAME_H

namespace YAX
{
	//class ContentManager;
	class GraphicsDevice;
	class LaunchParameters;
	class TimeSpan;
	struct GLFWwindow;

	class Game
	{
	public:
		Game();

		/* Content Pipeline NYI
		ContentManager& Content();
		void Content(const ContentManager&);*/
		

		YAX::GraphicsDevice& GraphicsDevice();
		void GraphicsDevice(YAX::GraphicsDevice);

		TimeSpan& InactiveSleepTime();
		void InactiveSleepTime(const TimeSpan&);

		bool IsActive();
		void IsActive(bool);

		bool IsFixedTimeStep();
		void IsFixedTimeStep(bool);

		bool IsMouseVisible();
		void IsMouseVisible(bool);

		YAX::LaunchParameters& LaunchParameters();
		void LaunchParameters(const YAX::LaunchParameters&);

		TimeSpan& TargetElapsedTime();
		void TargetElapsedTime(const TimeSpan&);

		GLFWwindow* Window();
		void Window(GLFWwindow*);


		void Exit();

		void ResetElapsedTime();

		void Run();

		void RunOneFrame();

		void SuppressDraw();

		void Tick();

	protected:
		virtual void BeginDraw();

		virtual void BeginRun();

		virtual void Draw();

		virtual void EndDraw();

		virtual void EndRun();

		virtual void Initialize();

		virtual void LoadContent();

		virtual void UnloadContent();

		virtual void Update();



	};
}
#endif