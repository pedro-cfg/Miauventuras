#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "Entidade.h"
#include "Jogador.h"

class Obstaculo: public Entidade 
{
public:
	Obstaculo();
	~Obstaculo();

	virtual void ExecutaImpedimento(Jogador* pJ) {}
	virtual void ExecutaImpedimento(Personagem* pP, bool esq, bool dir, bool cima, bool baixo) {}
};

#endif