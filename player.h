#pragma once
#include "olcPixelGameEngine.h"
class player
{
public:
	const float G = 1400;
	
	float maxVel = 600;
	float velY = 0;
	float x;
	float y;
	int width = 25;
	int height = 50;

	int jumpForce = -900;
	int strafeSpeed = 200;

	player();
	player(float x, float y);
	void RunPhysics(float dTime);
	void Draw(olc::PixelGameEngine* pge);
	void SetPos(float x, float y);
	void SetStrafeSpeed(int _newSpeed);
	float GetPosX();
	float GetPosY();
	float GetVelY();
	bool isColliding(float x1, float x2, float y1, float y2);

	void jump();
	void strafe(int dir, int maxX, float dTime);
};

