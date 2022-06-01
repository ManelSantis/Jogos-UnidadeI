#ifndef _WALL_H_
#define _WALL_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

enum TypeWall {
	SMALL,
	MEDIUM_H,
	MEDIUM_V,
	BIG_H,
	BIG_V
};

class Wall : public Object {

private:
	Sprite* wall = NULL;

public:
	Wall(); //Construtor padrão
	Wall(uint tipo); //Construtor com um tipo diferente de wall
	~Wall(); //Destrutor

	void Update();
	void Draw();
};

#endif
