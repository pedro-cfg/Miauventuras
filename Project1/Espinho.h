#ifndef _ESPINHO_H_
#define _ESPINHO_H_

#include "Obstaculo.h"

class Espinho: public Obstaculo 
{
private:
	static int cont;
public:
	Espinho();
	Espinho(float x, float y);
	~Espinho();

	static int getQuantidade();

	void ExecutaImpedimento(Jogador* pJ);

	void Gravar();
};

#endif