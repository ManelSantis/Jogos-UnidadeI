#ifndef _LEVEL3_H_
#define _LEVEL3_H_

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

class Level3 : public Game {

private:
	Sprite* background = nullptr;
	Scene* scene;
	int passarNivel = 9; //variavel usada para verificar quantas frutas o player já pegou

public:

	void Init();
	void Update();
	void Draw();
	void Finalize();
};

#endif
