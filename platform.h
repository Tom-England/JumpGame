#pragma once
#include "olcPixelGameEngine.h"
class platform
{
public:
	float x;
	float y;
	int width = 50;
	int height = 10;

	enum Type { Static, Moving, Collapsing };
	Type type = Static;
	int dir;
	bool enabled = true;

	olc::Pixel colour = olc::BLUE;

	platform();
	platform(float x, float y);

	void Draw(olc::PixelGameEngine* pge);
	void SetPos(float _x, float _y);
	void MoveDown(float amount);
	void MoveSide(float amount);
	void HandleType(float dTime, int ScreenWidth);
	void CheckPos(int ScreenHeight, int ScreenWidth);
	float GetPosX();
	float GetPosY();
	bool GetEnabled();
	void SetEnabled(bool value);
	Type GetType();
};

