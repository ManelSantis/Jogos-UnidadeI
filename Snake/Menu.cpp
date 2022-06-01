#include "Engine.h"
#include "Menu.h"
#include "GameOver.h"
#include "Level1.h"

Player* Menu::player = nullptr;
bool Menu::endless = NULL;

void Menu::Init() {
	background = new Sprite("Resources/Menu.png");
}

void Menu::Finalize() {
	delete background;
}

void Menu::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}

void Menu::Update() {
	if (window->KeyDown(VK_RETURN)) {
		endless = false;
		GameOver::score = 0;
		Engine::Next<Level1>();
	}
	if (window->KeyDown(VK_SPACE)) {
		endless = true;
		GameOver::score = 0;
		Engine::Next<Level1>();
	}
		
}