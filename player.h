#pragma once
#include "olcPixelGameEngine.h"
class player
{
public:
	const float G = 9.8;
	
	float maxVel = 10;

	float x;
	float y;

	player();
	player(float x, float y);
	void RunPhysics();
	void Draw(olc::PixelGameEngine* pge);
	void SetPos(float x, float y);
	float GetPosX();
	float GetPosY();
};

