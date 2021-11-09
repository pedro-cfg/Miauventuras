#ifndef GERENCIADOR_COLISOES_H_
#define GERENCIADOR_COLISOES_H_

#include "ListaEntidades.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Moeda.h"
#include "Personagem.h"

class Gerenciador_Colisoes {
private:
	/*ListaEntidades<Inimigo*> LIs;
	ListaEntidades<Obstaculo> LOs;
	ListaEntidades<Moeda> LMs;*/

	bool colidiu_cima, colidiu_baixo, colidiu_esquerda, colidiu_direita;
	Personagem* jogador;

public:
	Gerenciador_Colisoes(Personagem* jog);
	~Gerenciador_Colisoes();
		
	void Checa_Colisao(Personagem* segundo);
	void Reset_Checagem();

	bool getColidiuCima();
	bool getColidiuBaixo();
	bool getColidiuDireita();
	bool getColidiuEsquerda();
};

#endif 

