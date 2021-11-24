#ifndef _RATAO_H_
#define _RATAO_H_

#include "Inimigo.h"

class Ratao: public Inimigo 
{
public:
	Ratao();
	Ratao(float x, float y);
	~Ratao();

	//void setTipo();

	void Recuperar(float cX, float cY, float XI = 0.f, int numVidas = 0, float velX = 0.f, float velY = 0.f);
};

#endif 