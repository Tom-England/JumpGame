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
float platform::GetPosX() {
	return x;
}
float platform::GetPosY() {
	return y;
}