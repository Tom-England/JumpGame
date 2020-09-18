#pragma once
#include "olcPixelGameEngine.h"
class platform
{
public:
	float x;
	float y;
	int width = 50;
	int height = 10;

	platform();
	platform(float x, float y);

	void Draw(olc::PixelGameEngine* pge);
	void SetPos(float _x, float _y);
	void MoveDown(float amount);
	float GetPosX();
	float GetPosY();
};

