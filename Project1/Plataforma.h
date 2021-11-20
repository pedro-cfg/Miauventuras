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

	void setTipo();

	void Recuperar(float cX, float cY, float XI = 0.f, int numVidas = 0, float velX = 0.f, float velY = 0.f);
};

#endif