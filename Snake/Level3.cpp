#include "Engine.h"
#include "Level3.h"
#include "Menu.h"
#include "Fruit.h"
#include "GameOver.h"
#include "Congratulations.h"
#include "Wall.h"
#include <string>
#include <fstream>

using std::ifstream;
using std::string;

void Level3::Init() {
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
	wall->MoveTo(313, 148);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(353, 188);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(313, 352);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(352, 312);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(189, 148);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(149, 188);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(189, 352);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	wall = new Wall();
	wall->MoveTo(149, 312);
	scene->Add(wall, STATIC);
	fruit->AddWall(wall);

	fruit->Move();//Mover a fruta para algo que n esteja dentro das paredes

}

void Level3::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}

void Level3::Update() {

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
		Engine::Next<Congratulations>();
	}
}

void Level3::Finalize() {
	delete background;
	delete scene;
}
