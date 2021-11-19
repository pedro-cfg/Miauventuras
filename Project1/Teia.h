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

	void setTipo();

	void Recuperar(float cX, float cY, float XI = 0.f, int numVidas = 0);
};

#endif 