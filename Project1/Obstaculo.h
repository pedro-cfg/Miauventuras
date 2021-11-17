#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "Entidade.h"
#include "Jogador.h"

class Obstaculo: public Entidade 
{
protected:
	//static string tipo;
	bool ehPlataforma;
public:
	Obstaculo();
	~Obstaculo();

	bool getEhPlataforma();

	virtual void ExecutaImpedimento(Jogador* pJ) {}
	virtual void ExecutaImpedimento(Personagem* pP, bool esq, bool dir, bool cima, bool baixo) {}

	void Rotacionar();
	void setTipo();
};

#endif