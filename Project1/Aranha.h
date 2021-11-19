#ifndef _ARANHA_H_
#define _ARANHA_H_

#include "Inimigo.h"

class Projetil;

class Aranha: public Inimigo 
{
private:

public:
	Aranha();
	Aranha(float x, float y);
	~Aranha();

	void Executar(float dT);
	void lancaProjetil();

	void setTipo();

	void Recuperar(float cX, float cY, float XI = 0.f, int numVidas = 0);
};

#endif