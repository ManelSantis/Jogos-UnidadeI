#ifndef _BODY_H_
#define _BODY_H_

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

enum Direcao {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Body : public Object {

private:
	Sprite* body = NULL; //parte do corpo
	Body* before = NULL; //parte do corpo que se move antes da atual
	int direcao = -1;
	int posicao = -1;
	bool isHead = false; //verificar se é a cabeça da cobra

public:
	
	Body(); //Construtor
	~Body(); //Destrutor

	void setDirecao(int aux);
	int getDirecao();
	bool getHead();
	void setHead();

	void AddPosicao(int aux);
	void OnCollision(Object* obj);
	void AddBefore(Body* aux);
	Body* getBefore();
	void Update();
	void Draw();
};


#endif
