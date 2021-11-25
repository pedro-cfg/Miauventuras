#ifndef _LAGARTIXA_H_
#define _LAGARTIXA_H_

#include "Inimigo.h"

class Lagartixa: public Inimigo 
{
public:
	Lagartixa();
	Lagartixa(float x, float y);
	~Lagartixa();

	void reseta_velocidade();

	//void setTipo();

	void Recuperar(float cX, float cY, float XI = 0.f, int numVidas = 0, float velX = 0.f, float velY = 0.f);
	virtual void Gravar_Individual(fstream& arquivo);
};

#endif 