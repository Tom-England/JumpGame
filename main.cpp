#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "player.h"
#include "platform.h"
#include <iostream>
#include <vector>

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
	std::vector<platform> platforms;

	bool grounded = true;
	bool flipGrounded = false;
	int platMax = 9;

	float score = 0;

	std::unique_ptr<olc::Sprite> sprHero;
	std::unique_ptr<olc::Sprite> sprPlatform;
	std::unique_ptr<olc::Sprite> sprBackground;
	std::unique_ptr<olc::Sprite> sprWaves;
	std::unique_ptr<olc::Decal> decHero;
	std::unique_ptr<olc::Decal> decPlatform;
	std::unique_ptr<olc::Decal> decBackground;
	std::unique_ptr<olc::Decal> decWaves;

	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		p.SetPos(ScreenWidth()/2, ScreenHeight() - p.height);
		p.jump();
		p.SetStrafeSpeed(ScreenWidth());
		for (int platCount = 0; platCount < platMax; platCount++) {
			platforms.push_back(platform(rand() % (ScreenWidth() - 60) + 10, ScreenHeight()/platMax * platCount));
		}
		
		// Load the sprites
		
		sprHero = std::make_unique<olc::Sprite>("hero.png");
		sprPlatform = std::make_unique<olc::Sprite>("platform.png");
		sprBackground = std::make_unique<olc::Sprite>("background.png");
		sprWaves = std::make_unique<olc::Sprite>("waves.png");
		decHero = std::make_unique<olc::Decal>(sprHero.get());
		decPlatform = std::make_unique<olc::Decal>(sprPlatform.get());
		decBackground = std::make_unique<olc::Decal>(sprBackground.get());
		decWaves = std::make_unique<olc::Decal>(sprWaves.get());
		SetPixelMode(olc::Pixel::MASK);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		Clear(olc::BLUE);
		DrawDecal(olc::vf2d(0, 0), decBackground.get());

		flipGrounded = false;
		for (auto &pl : platforms) {
			pl.HandleType(fElapsedTime, ScreenWidth());

			// Checks if the bottom edge of the player is colliding with the current platform and moving down, if so flipGrounded is set to true
			if (pl.GetEnabled()) {
				if (p.isColliding(pl.x, pl.x + pl.width, pl.y, pl.y + pl.height)) {
					if (pl.GetType() == platform::Collapsing) { pl.SetEnabled(false); }
					else { flipGrounded = true; }
				}
			}
		}
		grounded = flipGrounded;

		// Player movement
		if (GetKey(olc::Key::A).bHeld) {
			p.strafe(-1, ScreenWidth(), fElapsedTime);
		}
		if (GetKey(olc::Key::D).bHeld) {
			p.strafe(1, ScreenWidth(), fElapsedTime);
		}

		if (!grounded) {
			// Runs physics on the player and moves the platforms down if player is above half way
			p.RunPhysics(fElapsedTime);
			if (p.GetPosY() < ScreenHeight() / 2 - p.height) {
				p.SetPos(p.GetPosX(), ScreenHeight() / 2 - p.height);
				for (int plIndex = 0; plIndex < platforms.size(); plIndex++) {
					platforms[plIndex].MoveDown(-p.GetVelY() * fElapsedTime);
					platforms[plIndex].CheckPos(ScreenHeight(), ScreenWidth());
				}
				score += fElapsedTime;
				std::cout << "Score: " << score << std::endl;
			}
		}
		else {
			// Sets the players velocity to 0 then makes them jump
			p.velY = 0;
			grounded = false;
			p.jump();
		}

		// Draws objects to screen
		for (auto pl : platforms) {
			//pl.Draw(this);
			if (pl.GetEnabled()) {
				DrawDecal(olc::vf2d(pl.GetPosX(), pl.GetPosY()), decPlatform.get());
			}
		}
		//p.Draw(this);
		DrawDecal(olc::vf2d(p.GetPosX(), p.GetPosY()), decHero.get());
		DrawDecal(olc::vf2d(0, ScreenHeight() - sprWaves.get()->height), decWaves.get());
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