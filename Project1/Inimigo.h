#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

class Inimigo: public Personagem
{
protected:

public:
	Inimigo();
	~Inimigo();

	void setTipo();
};

#endif