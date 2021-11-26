#ifndef _ESPINHO_H_
#define _ESPINHO_H_

#include "Obstaculo.h"

class Espinho: public Obstaculo 
{
public:
	Espinho();
	Espinho(float x, float y);
	~Espinho();

	void ExecutaImpedimento(Jogador* pJ);

	void Gravar();
};

#endif