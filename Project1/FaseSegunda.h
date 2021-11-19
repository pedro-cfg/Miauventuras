#ifndef _FASESEGUNDA_H_
#define _FASESEGUNDA_H_

#include "Fase.h"

class FaseSegunda: public Fase 
{
public:
	FaseSegunda(int* estado);
	~FaseSegunda();

	void Passou_Fase();

	void Gerar_Plataformas();
	void Gerar_Chefao();
};

#endif 