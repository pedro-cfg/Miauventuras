#ifndef _FASEPRIMEIRA_H_
#define _FASEPRIMEIRA_H_

#include "Fase.h"

class FasePrimeira: public Fase 
{
public:
	FasePrimeira();
	~FasePrimeira();

	void Executar(float dT);

	void Gerar_Plataformas();
};

#endif 