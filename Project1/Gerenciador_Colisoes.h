#ifndef GERENCIADOR_COLISOES_H_
#define GERENCIADOR_COLISOES_H_

#include "ListaEntidades.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Moeda.h"

class Gerenciador_Colisoes {
private:
	ListaEntidades<Inimigo*> LIs;
	ListaEntidades<Obstaculo> LOs;
	ListaEntidades<Moeda> LMs;
public:
	Gerenciador_Colisoes();
	~Gerenciador_Colisoes();
};

#endif 

