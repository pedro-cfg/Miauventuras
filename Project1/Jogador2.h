#ifndef _JOGADOR_2_H_
#define _JOGADOR_2_H_

#include "Jogador.h"

class Jogador2: public Jogador
{
public:
	Jogador2(float x, float y);
	Jogador2();
	~Jogador2();

	bool mover_esq();
	bool mover_dir();
	bool pular();
};

#endif