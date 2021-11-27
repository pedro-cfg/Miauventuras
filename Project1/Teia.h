#ifndef _TEIA_H_
#define _TEIA_H_

#include "Obstaculo.h"

class Teia: public Obstaculo 
{
private:
	static int cont;
public:
	Teia();
	Teia(float x, float y);
	~Teia();

	static int getQuantidade();

	void ExecutaImpedimento(Jogador* pJ);

	void Gravar();
};

#endif 