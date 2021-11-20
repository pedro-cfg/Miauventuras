#pragma once
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

