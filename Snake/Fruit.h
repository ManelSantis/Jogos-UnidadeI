#ifndef _FRUIT_H_
#define _FRUIT_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"
#include "Wall.h"
#include <vector>

class Fruit : public Object {

	private:
		Sprite* fruit = NULL;
		std::vector<Wall*> walls; //Se existir alguma parede em cena ela será adicionada aqui
		//Para impedir que a fruta nasça dentro da parede

	public:
		Fruit(); //Construtor
		~Fruit(); //Destrutor

		void AddWall(Wall* wall);
		bool TouchWall();
		void Update();
		void Move();
		void Draw();
};

#endif
