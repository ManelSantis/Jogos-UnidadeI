#include "Snake.h"
#include "Body.h"
#include "Menu.h"
#include "Fruit.h"

Body::Body() {

	body = new Sprite("Resources/Snake1.png");
	bbox = new Circle(15);
	type = SNAKE;

}

void Body::OnCollision(Object* obj) {
	if (isHead) {
		if (obj->Type() == FRUIT) {
			Fruit* aux1 = (Fruit*)obj;
			aux1->Move();

			while (aux1->X() == x || aux1->Y() == y) {
				aux1->Move();
			}

			Menu::player->GrowUp();
		}

		if (obj->Type() == SNAKE || obj->Type() == WALL) {
			Menu::player->StopBody();
		}
	}
}

void Body::AddBefore(Body* aux) {
	before = aux;
}

Body* Body::getBefore() {
	return before;
}

void Body::setDirecao(int aux) {
	direcao = aux;
}

int Body::getDirecao() {
	return direcao;
}

void Body::Update() {
	if (isHead) {
		if (getDirecao() == UP) {
			body = new Sprite("Resources/HeadU.png");
		}
		if (getDirecao() == DOWN) {
			body = new Sprite("Resources/HeadD.png");
		}
		if (getDirecao() == LEFT) {
			body = new Sprite("Resources/HeadL.png");
		}
		if (getDirecao() == RIGHT) {
			body = new Sprite("Resources/HeadR.png");
		}
	}
}

Body::~Body() {
	delete body;
	delete bbox;
}

bool Body::getHead() {
	return isHead;
}

void Body::setHead() {
	body = new Sprite("Resources/HeadR.png");
	isHead = true;
}

void Body::AddPosicao(int aux) {
	posicao = aux;
}

void Body::Draw() {
	if (posicao % 2 == 1) {
		body->Draw(x, y, Layer::FRONT);
	} else {
		body->Draw(x, y, Layer::MIDFRONT);
	}
	
}
