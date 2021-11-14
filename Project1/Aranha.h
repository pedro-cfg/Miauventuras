#ifndef _ARANHA_H_
#define _ARANHA_H_

#include "Inimigo.h"

class Projetil;

class Aranha: public Inimigo 
{
private:

public:
	Aranha(float x, float y);
	~Aranha();

	void Executar(float dT);
	void lancaProjetil();
};

#endif