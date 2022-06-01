#ifndef _MENU_H_
#define _MENU_H_

#include "Game.h"
#include "Sprite.h"
#include "Player.h"

class Menu : public Game
{
private:
	Sprite* background = nullptr; //Background

public:
	static Player* player; //Jogador principal
	static bool endless; //Verificar se o jogador estará indo para o modo sem fim
	void Init(); //Iniciar
	void Update(); //Atualizar
	void Draw(); //Desenhar
	void Finalize(); //Finalizar
};

#endif