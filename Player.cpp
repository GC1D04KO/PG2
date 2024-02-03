#include "Player.h"
#include<Novice.h>

Player::Player() {


	pos_ = { 500.0f,500.0f};
	speed_ = { 6.0f,6.0f };
	hpMax_ = 50.0f;
	hp_ = hpMax_;
	width = 64.0f;
	height = 64.0f;
	isAlive_ = true;
	CD = 0;
	score_ = 0;

}
void Player::Initalize() {

	pos_ = { 500.0f,500.0f };
	hpMax_ = 50.0f;
	hp_ = hpMax_;
	CD= 0;
	isAlive_ = true;
	score_ = 0;

}
void Player::Update(char* keys) {

	if (keys[DIK_W]) {
		pos_.y -= speed_.y;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_.y;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_.x;
	}
	 if (keys[DIK_D]) {
		pos_.x += speed_.x;
	}

	 if (CD > 0)
	 {
		 CD--;
	 }
	 else
	 {
		 CD = 15;
	 }
	 if (CD <= 0)
	 {
		 for (int i = 0; i < 10; i++)
		 {
			 if (keys[DIK_SPACE]) {
				 if (!bullet[i].isShot) {
					 bullet[i].pos_.x = pos_.x;
					 bullet[i].pos_.y = pos_.y;
					 bullet[i].isShot = true;
					 break;
				 }
			 }
		 }
	 }
	 for (int i = 0; i < 10; i++)
	 {
		 bullet[i].Update();
	 }



}
void Player::Draw() {

	int Texture_Player = Novice::LoadTexture("./Player.png");
	
	for (int i = 0; i < 10; i++)
	{
		bullet[i].Draw();
	}

	if (isAlive_)
	{
		Novice::DrawSprite((int)pos_.x,(int) pos_.y, Texture_Player, 1.0, 1.0, 0.0f, 0XFFFFFFFF);
	}

}

void Player::setHp(float hp) {
	this->hp_ = hp;
}
void Player::setIsAlive(bool IsAlive) {
	this->isAlive_ = IsAlive;
}

void Player::setScore(int score) {

	this->score_ = score;
}
