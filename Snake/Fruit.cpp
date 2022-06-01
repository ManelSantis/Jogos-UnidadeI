#include "Snake.h"
#include "Fruit.h"
#include <random>

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> numberWidth(25, 476); //escolher entre 25--475
std::uniform_int_distribution<int> numberHeight(25, 476); //escolher entre 25--475

Fruit::Fruit() {
	fruit = new Sprite("Resources/Fruit.png");
	bbox = new Rect(-13, -13, 13, 13);

	x = (float)numberWidth(mt);
	y = (float)numberHeight(mt);
	MoveTo(x, y);

	while (y == 250.0f || x == 250.0f || TouchWall()) {
		x = (float)numberWidth(mt);
		y = (float)numberHeight(mt);
		MoveTo(x, y);
	}

	type = FRUIT;
}

Fruit::~Fruit() {
	delete fruit;
	delete bbox;
}

void Fruit::Move() {
	if (walls.size() == 0) {
		x = (float)numberWidth(mt);
		y = (float)numberHeight(mt);
		MoveTo(x, y);
	} else {
		x = (float)numberWidth(mt);
		y = (float)numberWidth(mt);
		MoveTo(x, y);
		while (TouchWall()) {
			x = (float)numberWidth(mt);
			y = (float)numberHeight(mt);
			MoveTo(x, y);
		}
	}
}

bool Fruit::TouchWall() {
	Rect* aux = (Rect*)bbox;
	bool eixoX = false;
	bool eixoY = false;
	for (int i = 0; i < walls.size(); i++) {
		Rect* aux1 = (Rect*)walls[i]->bbox;

		eixoX = (aux->Left()+5 <= aux1->Right() && aux1->Left() <= aux->Right()+5);
		eixoY = (aux->Top()+5 <= aux1->Bottom() && aux1->Top() <= aux->Bottom()+5);

		if (eixoX) {
			if(eixoY)
			return true;
		}
	}
	return false;
}

void Fruit::AddWall(Wall* wall) {
	walls.push_back(wall);
}

void Fruit::Update() {

}

void Fruit::Draw() {
	fruit->Draw(x, y, Layer::MIDDLE);
}