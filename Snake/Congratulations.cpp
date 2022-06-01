#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"
#include "Menu.h"
#include "Congratulations.h"
#include "GameOver.h"

void Congratulations::Init() {
	background = new Sprite("Resources/Congratulations.png");

}

void Congratulations::Finalize() {
	delete background;
}

void Congratulations::Score() {
	string aux = std::to_string(GameOver::score);
	string png = ".png";
	float posX = float(window->CenterX());
	float posY = 294.0f;
	Sprite* pont;
	for (int i = 0; i < aux.length(); i++) {
		string caminho = aux[i] + png;
		pont = new Sprite("Resources/" + caminho);
		pont->Draw(posX, posY, Layer::FRONT);
		posX += 20;
	}

	pont = new Sprite("Resources/Fruit.png");
	pont->Draw(posX + 10, posY, Layer::FRONT);
}

void Congratulations::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	Score();
}

void Congratulations::Update() {
	if (window->KeyDown(VK_ESCAPE)) {
		Sleep(500);
		Engine::Next<Menu>();
	}
}