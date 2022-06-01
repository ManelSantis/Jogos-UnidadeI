#ifndef _CONGRATULATIONS_H_
#define _CONGRATULATIONS_H_

#include "Game.h"
#include "Sprite.h"

class Congratulations : public Game {
private:
	Sprite* background = nullptr; //Background

public:
	void Init(); //Iniciar
	void Update(); //Atualizar
	void Draw(); //Desenhar
	void Finalize(); //Finalizar
	void Score();
};

#endif