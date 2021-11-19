#ifndef _FASEPRIMEIRA_H_
#define _FASEPRIMEIRA_H_

#include "Fase.h"

class FasePrimeira: public Fase 
{
public:
	FasePrimeira(int* estado);
	~FasePrimeira();

	void Passou_Fase();

	void Gerar_Plataformas();
};

#endif 