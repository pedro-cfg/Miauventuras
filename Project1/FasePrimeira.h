#ifndef _FASEPRIMEIRA_H_
#define _FASEPRIMEIRA_H_

#include "Fase.h"

class FasePrimeira: public Fase 
{
public:
	FasePrimeira(Jogador* j1);
	~FasePrimeira();

	void Executar(float dT);

	void Gerar_Objetos();

	void Inserir_Inimigos();
};

#endif 