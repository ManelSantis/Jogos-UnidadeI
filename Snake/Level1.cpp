#include "Engine.h"
#include "Level1.h"
#include "Level2.h"
#include "Menu.h"
#include "Fruit.h"
#include "GameOver.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

void Level1::Init() {
	scene = new Scene();
	Menu::player = new Player();
	background = new Sprite("Resources/Levels.png");
	scene->Add(Menu::player, MOVING); //adicionar o player
	std::vector<Body*> aux = Menu::player->AddScene(); //adicionar o corpo

	for (int i = 0; i < aux.size(); i++) {
		scene->Add(aux[i], MOVING);
	}
	
	Fruit* fruit = new Fruit();
	scene->Add(fruit, STATIC);

}

void Level1::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}

void Level1::Update() {

	//Crescer o corpo
	if (Menu::player->grow) {
		scene->Add(Menu::player->GrowOnScene(), MOVING);
	}

	scene->Update();
	scene->CollisionDetection();

	if (Menu::player->isOver()) {
		Sleep(500);
		GameOver::score += Menu::player->AddScene().size() - 3;
		Engine::Next<GameOver>();
	}

	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<Menu>();
	}

	if (Menu::player->AddScene().size() - 3 == passarNivel && !Menu::endless) {
		GameOver::score += Menu::player->AddScene().size() - 3;
		Engine::Next<Level2>();
	}
}

void Level1::Finalize() {
	delete background;
	delete scene;
}
