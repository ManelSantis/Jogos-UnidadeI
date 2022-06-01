#include "Engine.h"
#include "Snake.h"
#include "Player.h"

Player::Player() {
	grow = false;
	timer->Start();
	bbox = new Rect(0, 0, 0, 0);
	float aux = 250.0f;
	for (int i = 0; i < 3; i++) {
		Body* aux1 = new Body();
		aux1->MoveTo(aux, 250.0f);
		aux -= 45.0f;
		body.push_back(aux1);

		if (i > 0) {
			body[i]->AddBefore(body[i - 1]);
		}
		body[i]->AddPosicao(i + 1);

	}	
	body[0]->setDirecao(RIGHT);
	body[0]->setHead();

	type = SNAKE;
}

vector<Body*> Player::AddScene() {
	return body;
}

Body* Player::GrowOnScene(){
	grow = false;
	return body[body.size() - 1];
}

Player::~Player() {
	//delete body;
	delete bbox;
}

void Player::Up() {
	velX = 0;
	velY = -150.0f;
}

void Player::Down() {
	velX = 0;
	velY = 150.0f;
}

void Player::Right() {
	velX = 150;
	velY = 0;
}

void Player::Left() {
	velX = -150;
	velY = 0;
}

void Player::OnCollision(Object* obj) {
	
}

void Player::Update() {
	//UP
	if (window->KeyDown(VK_UP)) {
		if (velY == 0 && TimeBtwMoves()) {
			timer->Reset();
			timer->Start();
			Up();
			body[0]->setDirecao(UP);
		}
	}
	//Down
	if (window->KeyDown(VK_DOWN)) {
		if (velY == 0 && TimeBtwMoves()) {
			timer->Reset();
			timer->Start();
			Down();
			body[0]->setDirecao(DOWN);
		}
	}
	//Left
	if (window->KeyDown(VK_LEFT)) {
		if (velX == 0 && TimeBtwMoves()) {
			timer->Reset();
			timer->Start();
			Left();
			body[0]->setDirecao(LEFT);
		}
	}
	//Right
	if (window->KeyDown(VK_RIGHT)) {
		if (velX == 0 && TimeBtwMoves()) {
			timer->Reset();
			timer->Start();
			Right();
			body[0]->setDirecao(RIGHT);
		}
	}
	//Mover cabeça
	body[0]->Translate(velX * gameTime, velY * gameTime);
	//Mover corpo
	if (!gameOver) {
		MoveBody();
	}
	//Veriicar se a cabeça bateu na parede
	//RIGHT
	if (body[0]->X() >= window->Width() - 27) {
		StopBody();
	}
	//LEFT
	if (body[0]->X() <= 27) {
		StopBody();
	}
	//DOWN
	if (body[0]->Y() >= window->Height() - 27) {
		StopBody();
	}
	//UP
	if (body[0]->Y() <= 27) {
		StopBody();
	}
}

bool Player::isOver() {
	return gameOver;
}

void Player::StopBody() {
	//Para o jogo
	velX = 0;
	velY = 0;
	timer->Stop();
	body[0]->setDirecao(-1);
	gameOver = true;
}

bool Player::TimeBtwMoves() {
	//Metodo que ajuda a verificar quanto tempo faz 
	//Que o usuario clicou em uma tecla para se moviemtnar
	tempo = timer->Elapsed();
	if (tempo >= 0.35f) {
		return true;
	} else {
		return false;
	}
}

void Player::MoveBody() {
	//MOVIMENTAR O CORPO
	float distancia; //Verificar distancia entre as partes do corpo da cobra
	for (int i = 1; i < body.size(); i++) {
		//UP
		if (body[i]->getBefore()->getDirecao() == UP) {
			if (body[i]->getBefore()->X() == body[i]->X()) {
				body[i]->Translate(0 * gameTime, -150 * gameTime);
				body[i]->setDirecao(UP);
				distancia = body[i]->Y() - body[i]->getBefore()->Y();
				if (distancia != 45.0f) {
					body[i]->MoveTo(body[i]->X(), body[i]->getBefore()->Y() + 45.0f);
				}
			}
			else {

				if (body[i]->getDirecao() == RIGHT) {
					body[i]->Translate(150 * gameTime, 0 * gameTime);
					if (body[i]->X() > body[i - 1]->X()) {
						body[i]->MoveTo(body[i]->getBefore()->X(), body[i]->Y());
					}
				}

				if (body[i]->getDirecao() == LEFT) {
					body[i]->Translate(-150 * gameTime, 0 * gameTime);
					if (body[i]->X() < body[i - 1]->X()) {
						body[i]->MoveTo(body[i]->getBefore()->X(), body[i]->Y());
					}
				}

			}
		}
		//DOWN
		if (body[i]->getBefore()->getDirecao() == DOWN) {
			if (body[i]->getBefore()->X() == body[i]->X()) {
				body[i]->Translate(0 * gameTime, 150 * gameTime);
				body[i]->setDirecao(DOWN);
				distancia = body[i]->getBefore()->Y() - body[i]->Y();
				if (distancia != 45.0f) {
					body[i]->MoveTo(body[i]->X(), body[i]->getBefore()->Y() - 45.0f);
				}
			}
			else {

				if (body[i]->getDirecao() == RIGHT) {
					body[i]->Translate(150 * gameTime, 0 * gameTime);
					if (body[i]->X() > body[i - 1]->X()) {
						body[i]->MoveTo(body[i]->getBefore()->X(), body[i]->Y());
					}
				}

				if (body[i]->getDirecao() == LEFT) {
					body[i]->Translate(-150 * gameTime, 0 * gameTime);
					if (body[i]->X() < body[i - 1]->X()) {
						body[i]->MoveTo(body[i]->getBefore()->X(), body[i]->Y());
					}
				}

			}
		}
		//LEFT
		if (body[i]->getBefore()->getDirecao() == LEFT) {
			if (body[i]->getBefore()->Y() == body[i]->Y()) {
				body[i]->Translate(-150 * gameTime, 0 * gameTime);
				body[i]->setDirecao(LEFT);
				distancia = body[i]->X() - body[i]->getBefore()->X();
				if (distancia != 45.0f) {
					body[i]->MoveTo(body[i]->getBefore()->X() + 45.0f, body[i]->Y());
				}
			}
			else {

				if (body[i]->getDirecao() == UP) {
					body[i]->Translate(0 * gameTime, -150 * gameTime);
					if (body[i]->Y() < body[i - 1]->Y()) {
						body[i]->MoveTo(body[i]->X(), body[i]->getBefore()->Y());
					}
				}

				if (body[i]->getDirecao() == DOWN) {
					body[i]->Translate(0 * gameTime, 150 * gameTime);
					if (body[i]->Y() > body[i - 1]->Y()) {
						body[i]->MoveTo(body[i]->X(), body[i]->getBefore()->Y());
					}
				}

			}
		}
		//RIGHT
		if (body[i]->getBefore()->getDirecao() == RIGHT) {
			if (body[i]->getBefore()->Y() == body[i]->Y()) {
				body[i]->Translate(150 * gameTime, 0 * gameTime);
				body[i]->setDirecao(RIGHT);
				distancia = body[i]->getBefore()->X() - body[i]->X();
				if (distancia != 45.0f) {
					body[i]->MoveTo(body[i]->getBefore()->X() - 45.0f, body[i]->Y());
				}
			}
			else {

				if (body[i]->getDirecao() == UP) {
					body[i]->Translate(0 * gameTime, -150 * gameTime);
					if (body[i]->Y() < body[i - 1]->Y()) {
						body[i]->MoveTo(body[i]->X(), body[i]->getBefore()->Y());
					}
				}

				if (body[i]->getDirecao() == DOWN) {
					body[i]->Translate(0 * gameTime, 150 * gameTime);
					if (body[i]->Y() > body[i - 1]->Y()) {
						body[i]->MoveTo(body[i]->X(), body[i]->getBefore()->Y());
					}
				}

			}
		}
		distancia = 0.0f;
	}
}

void Player::GrowUp() {
	Body* aux1 = new Body();
	//Verifica em que direção a ponta da calda está indo
	//UP
	if (body[body.size() - 1]->getDirecao() == UP) {
		aux1->setDirecao(UP);
		aux1->AddBefore(body[body.size() - 1]);
		aux1->MoveTo(aux1->getBefore()->X(), aux1->getBefore()->Y() + 45.0f);
	}
	//DOWN
	if (body[body.size() - 1]->getDirecao() == DOWN) {
		aux1->setDirecao(DOWN);
		aux1->AddBefore(body[body.size() - 1]);
		aux1->MoveTo(aux1->getBefore()->X(), aux1->getBefore()->Y() - 45.0f);
	}
	//LEFT
	if (body[body.size() - 1]->getDirecao() == LEFT) {
		aux1->setDirecao(LEFT);
		aux1->AddBefore(body[body.size() - 1]);
		aux1->MoveTo(aux1->getBefore()->X() + 45.0f, aux1->getBefore()->Y());
	}
	//RIGHT
	if (body[body.size() - 1]->getDirecao() == RIGHT) {
		aux1->setDirecao(RIGHT);
		aux1->AddBefore(body[body.size() - 1]);
		aux1->MoveTo(aux1->getBefore()->X() - 45.0f, aux1->getBefore()->Y());
	}

	body.push_back(aux1);
	body[body.size() - 1]->AddPosicao(body.size());//Adicionar a posição da parte do corpo
	grow = true;
}

void Player::Draw() {
	for (int i = 0; i < body.size(); i++) {
		body[i]->Draw();
	}
}
