#include "platform.h"
#include <iostream>

platform::platform() {
	x = 0;
	y = 0;
	dir = rand() % 1;
	if (dir == 0) { dir = -1; }
}
platform::platform(float _x, float _y) {
	x = _x;
	y = _y;
	dir = rand() % 1;
	if (dir == 0) { dir = -1; }
}
void platform::Draw(olc::PixelGameEngine* pge) {
	pge->FillRect(olc::vf2d(x, y), { width, height }, colour);
}
void platform::SetPos(float _x, float _y) {
	x = _x;
	y = _y;
}
void platform::MoveDown(float amount) {
	y += amount;
}
void platform::MoveSide(float amount) {
	x += amount;
}
void platform::HandleType(float dTime, int ScreenWidth) {
	switch (type) {
		case Moving:
			MoveSide((float)(1 * dir));
			if (GetPosX() + width >= ScreenWidth - 10 && dir == 1) { dir = -1; }
			if (GetPosX() <= 10 && dir == -1) { dir = 1; }
			
		break;
		case Collapsing:

		break;
	}
}
void platform::CheckPos(int ScreenHeight, int ScreenWidth) {
	if (y > ScreenHeight) {
		SetPos(rand() % (ScreenWidth - 60) + 10, 0);
		int newType = rand() % 100 + 1;
		if (newType <= 70) { type = Static; colour = olc::BLUE; }
		else if (newType <= 90) { type = Moving; colour = olc::GREEN; }
		else if (newType <= 95) { type = Collapsing; colour = olc::CYAN; }
	}
}
float platform::GetPosX() {
	return x;
}
float platform::GetPosY() {
	return y;
}