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
	
	bool colidiu_cima, colidiu_baixo, colidiu_esquerda, colidiu_direita;
	Jogador* jogador;

public:
	Gerenciador_Colisoes(Jogador* jog);
	~Gerenciador_Colisoes();
		
	bool getColidiuCima() const;
	bool getColidiuBaixo() const;
	bool getColidiuDireita() const;
	bool getColidiuEsquerda() const;

	void InserirInimigo(Inimigo* pI);
	void InserirObstaculo(Obstaculo* pO);

	void Checa_Colisao();
	void Checa_Colisao_Individual(Entidade* segundo);
};

#endif 

