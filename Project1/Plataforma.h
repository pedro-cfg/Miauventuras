#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "Obstaculo.h"

class Plataforma: public Obstaculo 
{
public:
	Plataforma();
	Plataforma(float x, float y);
	~Plataforma();

	void ExecutaImpedimento(Personagem* pP, bool esq, bool dir, bool cima, bool baixo);

	void Gravar();
};

#endif