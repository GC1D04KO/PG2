#include "Scene.h"
#include<Novice.h>

Scene::Scene() {

	scene = Title;
};
void Scene::Initalize() {
	
	scene = Title;


}
void Scene::Update(char* keys, char* preKeys, Player obj) {

	switch (scene)
	{
	case Title:

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			scene = Game;
		}



		break;

	case Game:

		if (obj.getHp() <= 0)
		{
			scene = GameOver;
		}

		if (obj.getScore() >= 20)
		{
			scene = GameClear;
		}

		break;
	case GameClear:
		

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			  Initalize();
		}
		



		break;


	case GameOver:



		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
		{
			Initalize();
		}

		break;
	
	}

}
void Scene::Draw() {

	int Texture_Title = Novice::LoadTexture("./Title.png");
	int Texture_Game = Novice::LoadTexture("./Game.png");
    int Texture_GameClear = Novice::LoadTexture("./GameClear.png");
	int Texture_GameOver = Novice::LoadTexture("./GameOver.png");

	switch (scene)
	{
	case Title:


		Novice::DrawSprite(0, 0, Texture_Title, 1, 1, 0.0f, 0xffffffff);

		break;


	case Game:

		Novice::DrawSprite(0, 0, Texture_Game, 1, 1, 0.0f, 0xffffffff);

		break;

	 
	case GameOver:

		Novice::DrawSprite(0, 0, Texture_GameOver, 1, 1, 0.0f, 0xffffffff);

		break;


	case GameClear:


		Novice::DrawSprite(0, 0, Texture_GameClear, 1, 1, 0.0f, 0xffffffff);
		break;



	}

}