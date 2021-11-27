#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "Entidade.h"
#include "Jogador.h"

class Obstaculo: public Entidade 
{
protected:
	bool EhPlataforma;
public:
	Obstaculo();
	virtual~Obstaculo();

	virtual void ExecutaImpedimento(Jogador* pJ) {}
	virtual void ExecutaImpedimento(Personagem* pP, const bool esq, const bool dir, const bool cima, const bool baixo) {}

	void Executar(float dT){}

	const bool getEhPlataforma() const;

	void GravarInfo(fstream& arquivo);
	void Carregar(fstream& arquivo);
};

#endif