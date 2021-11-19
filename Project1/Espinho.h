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

	void setTipo();

	void Recuperar(float cX, float cY, float XI = 0.f, int numVidas = 0);
};

#endif