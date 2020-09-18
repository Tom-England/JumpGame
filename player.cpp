#include "player.h"

player::player() {
	x = 0;
	y = 0;
}
player::player(float _x, float _y) {
	x = _x;
	y = _y;
}
void player::Draw(olc::PixelGameEngine* pge) {
	pge->FillRect(olc::vf2d( x, y ), { 25, 50 }, olc::RED);
}
void player::SetPos(float _x, float _y) {
	x = _x;
	y = _y;
}
float player::GetPosX() {
	return x;
}
float player::GetPosY() {
	return y;
}