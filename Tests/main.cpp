//For testing purposes

#include <iostream>
#include "../YAX/include/Game.h"
#include "../YAX/include/GraphicsDeviceManager.h"
#include "../YAX/include/GameTime.h"

using namespace YAX;

class Game1 : public Game
{
	using Base = Game;

public:
	GraphicsDeviceManager graphics;

	Game1()
		: Base(), 
		graphics(this)
	{}

protected:
	void Initialize() override
	{
		Base::Initialize();
	}

	void Update(const GameTime& gt) override
	{
		Base::Update(gt);
	}

	void Draw() override
	{
		Base::Draw();
	}

};


int main()
{
	
}
