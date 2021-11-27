#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "Obstaculo.h"

class Plataforma: public Obstaculo 
{
private:
	static int cont;
public:
	Plataforma();
	Plataforma(float x, float y);
	~Plataforma();

	static int getQuantidade();

	void ExecutaImpedimento(Personagem* pP, const bool esq, const bool dir, const bool cima, const bool baixo);

	static void reseta_cont();
	void Gravar();
};

#endif