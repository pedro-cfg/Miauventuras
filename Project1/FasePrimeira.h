#ifndef _FASEPRIMEIRA_H_
#define _FASEPRIMEIRA_H_

#include "Fase.h"

class FasePrimeira: public Fase 
{
private:
	int& estado_jogo;
public:
	FasePrimeira(int* estado);
	~FasePrimeira();

	void Passou_Fase();

	void Gerar_Plataformas();

	void Limpar();

	void GravarLista(fstream& arquivo);

	void LerLista(fstream& arquivo);

	void LerLista_Individual(fstream& arquivo);
};

#endif 