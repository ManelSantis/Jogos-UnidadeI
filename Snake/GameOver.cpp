#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"
#include "Menu.h"
#include "GameOver.h"

int GameOver::score = 0;

void GameOver::Init() {
	background = new Sprite("Resources/GameOver.png");
	
}

void GameOver::Finalize() {
	delete background;
}

void GameOver::Score() {
	string aux = std::to_string(score);
	string png = ".png";
	float posX = float(window->CenterX());
	float posY = 266.0f;
	Sprite* pont;
	for (int i = 0; i < aux.length(); i++) {
		string caminho = aux[i] + png;
		pont = new Sprite("Resources/" + caminho);
		pont->Draw(posX, posY, Layer::FRONT);
		posX += 20;
	}
	
	pont = new Sprite("Resources/Fruit.png");
	pont->Draw(posX+10, posY, Layer::FRONT);
}

void GameOver::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	Score();
}

void GameOver::Update() {
	if (window->KeyDown(VK_ESCAPE)) {
		Sleep(500);
		Engine::Next<Menu>();
	}
}