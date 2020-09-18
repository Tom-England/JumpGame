#pragma once
#include "olcPixelGameEngine.h"
class player
{
public:
	const float G = 2;
	
	float maxVel = 10;
	float velY = 0;
	float x;
	float y;

	player();
	player(float x, float y);
	void RunPhysics(float dTime);
	void Draw(olc::PixelGameEngine* pge);
	void SetPos(float x, float y);
	float GetPosX();
	float GetPosY();
};

