#include "Bullet.h"
#include<Novice.h>

Bullet::Bullet()
{
	pos_ = { -100.0f,-100.0f };
	isShot = false;
	width = 32.0f;
	height = 32.0f;
	speed_= { 30.0f,30.f };
}
void Bullet::Initalize() {
	pos_ = { -100.0f,100.0f };
	isShot = false;
}

void  Bullet::Update() {
	if (isShot)
	{
		pos_.x += speed_.x;
		if (pos_.x > 1280) {
			isShot = false;
		}
	}
}
void Bullet::Draw() {

	if (isShot)
	{
		int Texture_Bullet = Novice::LoadTexture("./Bullet.png");

		Novice::DrawSprite((int)pos_.x, (int)pos_.y, Texture_Bullet, 1, 1, 0.0f, 0xffffffff);
	}
}
