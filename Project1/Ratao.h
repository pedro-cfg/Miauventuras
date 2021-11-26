#ifndef _RATAO_H_
#define _RATAO_H_

#include "Inimigo.h"

class Ratao: public Inimigo 
{
public:
	Ratao();
	Ratao(float x, float y);
	~Ratao();

	void Gravar();
};

#endif 