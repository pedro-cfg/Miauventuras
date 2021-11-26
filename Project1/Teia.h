#ifndef _TEIA_H_
#define _TEIA_H_

#include "Obstaculo.h"

class Teia: public Obstaculo 
{
public:
	Teia();
	Teia(float x, float y);
	~Teia();

	void ExecutaImpedimento(Jogador* pJ);

	void Gravar();
};

#endif 