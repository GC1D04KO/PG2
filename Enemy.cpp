#include "Enemy.h"
#include<Novice.h>
#include<stdlib.h>
#include<time.h>

Enemy::Enemy()
{
	pos_ = { 1400.0f, float(rand() % 656) };
	speed_ = { 10.0f,10.0f };
	width = 64.0f;
	height = 64.0f;
	isAlive_ = false;
	IsTimer = 120 + rand() % 121;

}
 
void Enemy::Initalize()
{
	pos_ = { 1400.0f, float(rand() % 656) };

	isAlive_ = false;

	IsTimer = 120 + rand() % 121;
}

void Enemy::Update()
{
	if (!isAlive_)
	{
		if (IsTimer > 0)
		{
			IsTimer--;
		}
		else {
			pos_.x = 1400.0f;
			pos_.y = float(rand() % 656);
			isAlive_ = true;
			IsTimer = 180;

		}
	}
	
	 
 else {
		pos_.x-= speed_.x;
		pos_.y += speed_.y;

		if (pos_.y <= 0 || pos_.y >= 656)
		{
			speed_.y *= -1;
		}
		if (pos_.x < -64.0f)
		{
			isAlive_ = false;
		}



 }

}
void Enemy::Draw()
{
	int Texture_Enemy = Novice::LoadTexture("./Enemy.png");

	if (isAlive_)
	{
		Novice::DrawSprite((int)pos_.x, (int)pos_.y, Texture_Enemy, 1, 1, 0.0f, 0xffffffff);
	}

}
void Enemy::setIsAlive(bool isAlive)
{
	this->isAlive_ = isAlive;
}

 