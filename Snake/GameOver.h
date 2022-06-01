#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include "Game.h"
#include "Sprite.h"

class GameOver : public Game {
	private:
		Sprite* background = nullptr; //Background
		
	public:
		static int score; //Pontuação
		void Init(); //Iniciar
		void Update(); //Atualizar
		void Draw(); //Desenhar
		void Finalize(); //Finalizar
		void Score();
};

#endif