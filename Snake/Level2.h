#ifndef _LEVEL2_H_
#define _LEVEL2_H_

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

class Level2: public Game {

private:
	Sprite* background = nullptr;
	Scene* scene;
	int passarNivel = 7; //variavel usada para verificar quantas frutas o player já pegou

public:

	void Init();
	void Update();
	void Draw();
	void Finalize();
};

#endif
