#include "Snake.h"
#include "Wall.h"

Wall::Wall() {
	wall = new Sprite("Resources/Wall0.png");
	bbox = new Rect(-20, -20, 20, 20);
	type = WALL;
}

Wall::Wall(uint tipo) {
	if (tipo == MEDIUM_H) {
		wall = new Sprite("Resources/Wall1.png");
		bbox = new Rect(-40, -20, 40, 20);
	}

	if (tipo == BIG_H) {
		wall = new Sprite("Resources/Wall2.png");
		bbox = new Rect(-60, -20, 60, 20);
	}

	if (tipo == MEDIUM_V) {
		wall = new Sprite("Resources/Wall3.png");
		bbox = new Rect(-20, -40, 20, 40);
	}

	if (tipo == BIG_V) {
		wall = new Sprite("Resources/Wall4.png");
		bbox = new Rect(-20, -80, 20, 80);
	}

	type == WALL;
}

Wall::~Wall() {
	delete wall;
}

void Wall::Update() {

}

void Wall::Draw() {
	wall->Draw(x, y, Layer::MIDDLE);
}