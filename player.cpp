#include "player.h"

player::player() {
	x = 0;
	y = 0;
}
player::player(float _x, float _y) {
	x = _x;
	y = _y;
}
void player::RunPhysics(float dTime) {
	velY += G * dTime;
	if (velY > maxVel) { velY = maxVel; }
	y += velY * dTime;
}
void player::Draw(olc::PixelGameEngine* pge) {
	pge->FillRect(olc::vf2d( x, y ), { 25, 50 }, olc::RED);
}
void player::SetPos(float _x, float _y) {
	x = _x;
	y = _y;
}
void player::SetStrafeSpeed(int _newSpeed) {
	strafeSpeed = _newSpeed;
}
float player::GetPosX() {
	return x;
}
float player::GetPosY() {
	return y;
}
float player::GetVelY() {
	return velY;
}
bool player::isColliding(float x1, float x2, float y1, float y2) {
	if (velY >= 0) {
		if (x > x1 && x < x2) {
			if (y + height > y1 && y + height < y2) {
				return true;
			}
		}
		if (x + width > x1 && x + width < x2) {
			if (y + height > y1 && y + height < y2) {
				return true;
			}
		}
	}
	return false;
}

void player::jump() {
	velY += jumpForce;
}
void player::strafe(int dir, int maxX, float dTime) {
	// -1 is left, 1 is right
	x += strafeSpeed * dir * dTime;
	if (x < 0) { x = maxX; }
	if (x > maxX) { x = 0; }
}