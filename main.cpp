#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "player.h"
#include <iostream>

// Override base class with your custom functionality
class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		// Name you application
		sAppName = "JumpGame";
	}

public:
	//player p = player((float)ScreenWidth()/2.0f, (float)ScreenHeight()/2.0f);
	player p;
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		Clear(olc::WHITE);
		p.Draw(this);
		return true;
	}
};

int main()
{
	Game jumpGame;
	if (jumpGame.Construct(600, 900, 1, 1))
		jumpGame.Start();
	return 0;
}