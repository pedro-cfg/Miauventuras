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

	void Gravar();
};

#endif 