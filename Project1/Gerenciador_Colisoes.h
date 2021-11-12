#ifndef GERENCIADOR_COLISOES_H_
#define GERENCIADOR_COLISOES_H_

#include "ListaEntidades.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Entidade.h"
#include "Jogador.h"

class Gerenciador_Colisoes 
{
private:
	list<Inimigo*> LIs;
	list<Obstaculo*> LOs;

public:
	Gerenciador_Colisoes();
	~Gerenciador_Colisoes();

	void InserirInimigo(Inimigo* pI);
	void InserirObstaculo(Obstaculo* pO);

	void Checa_Colisao(Jogador* pJ);
	void Checa_Colisao_Individual(Jogador* pJ, Entidade* outro);

	void Executa_Colisao(Jogador* pJ, Inimigo* inimigo);
	void Executa_Colisao(Jogador* pJ, Obstaculo* obstaculo);
};

#endif 

