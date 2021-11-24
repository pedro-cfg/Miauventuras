#ifndef _JOGADOR_1_H_
#define _JOGADOR_1_H_

#include "Jogador.h"

class Jogador1: public Jogador
{
public:
	Jogador1(float x, float y);
	Jogador1();
	~Jogador1();

	bool mover_esq();
	bool mover_dir();
	bool pular();
};

#endif