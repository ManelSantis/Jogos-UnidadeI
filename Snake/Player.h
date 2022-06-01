#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"
#include "Body.h"
#include "Timer.h"
#include <vector>

class Player : public Object {

	private:
		std::vector<Body*> body;
		float velX = 150;
		float velY = 0;
		Timer* timer = new Timer();;
		float tempo = 0.0f;
		bool gameOver = false;
	

	public:
		bool grow = false;
		Player(); //Construtor
		~Player(); //Destrutor

		void Up();
		void Down();
		void Left();
		void Right();
		
		bool TimeBtwMoves();
		
		std::vector<Body*> AddScene(); //Ajudar a adicionar o corpo na cena
		Body* GrowOnScene(); //Corpo crescer na cena

		void GrowUp();
		void OnCollision(Object* obj);
		void MoveBody();
		bool isOver();
		void StopBody();
		void Update();
		void Draw();
};


#endif