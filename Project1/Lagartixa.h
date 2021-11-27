#ifndef _LAGARTIXA_H_
#define _LAGARTIXA_H_

#include "Inimigo.h"

class Lagartixa: public Inimigo 
{
private:
	static int cont;
public:
	Lagartixa();
	Lagartixa(float x, float y);
	~Lagartixa();

	static int getQuantidade();

	void reseta_velocidade();

	void Gravar();
};

#endif 