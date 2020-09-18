#include "platform.h"

platform::platform() {
	x = 0;
	y = 0;
}
platform::platform(float _x, float _y) {
	x = _x;
	y = _y;
}
void platform::Draw(olc::PixelGameEngine* pge) {
	pge->FillRect(olc::vf2d(x, y), { width, height }, olc::BLUE);
}
void platform::SetPos(float _x, float _y) {
	x = _x;
	y = _y;
}
void platform::MoveDown(float amount) {
	y += amount;
}
void platform::CheckPos(int ScreenHeight, int ScreenWidth) {
	if (y > ScreenHeight) {
		SetPos(rand() % (ScreenWidth - 60) + 10, 0);
	}
}
float platform::GetPosX() {
	return x;
}
float platform::GetPosY() {
	return y;
}