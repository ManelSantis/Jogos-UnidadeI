#include "Engine.h"
#include "Level2.h"
#include "Level3.h"
#include "Menu.h"
#include "Fruit.h"
#include "GameOver.h"
#include "Wall.h"
#include <string>
#include <fstream>

using std::ifstream;
using std::string;

void Level2::Init() {
	scene = new Scene();
	Menu::player = new Player();
	background = new Sprite("Resources/Levels.png");
	scene->Add(Menu::player, MOVING); //adicionar o player
	std::vector<Body*> aux = Menu::player->AddScene(); //adicionar o corpo

	for (int i = 0; i < aux.size(); i++) {
		scene->Add(aux[i], MOVING);
	}

	//Adiciona Fruta na cena
	Fruit* fruit = new Fruit();
	scene->Add(fruit, STATIC);

	//Adiciona Paredes na cena
	Wall* wall = new Wall();
	wall->MoveTo(25, 148);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(475, 148);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(25, 352);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(475, 352);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall(MEDIUM_H);
	wall->MoveTo(252, 67);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	fruit->Move();//Mover a fruta para algo que n esteja dentro das paredes
}

void Level2::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}

void Level2::Update() {

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
		Engine::Next<Level3>();
	}
}

void Level2::Finalize() {
	delete background;
	delete scene;
}
