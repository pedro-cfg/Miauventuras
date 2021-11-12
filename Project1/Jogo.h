#ifndef _JOGO_H_
#define _JOGO_H_

#include "Jogador.h"
#include "Aranha.h"
#include "Lagartixa.h"
#include "Ratao.h"
#include "Plataforma.h"
#include "Gerenciador_Colisoes.h"
#include "Gerenciador_Grafico.h"
#include "Lista.h"
#include "Entidade.h"
#include "Marcador_Vida.h"

class Jogo 
{
private:
	Jogador j1;
	Aranha a1;
	Lagartixa l1;
	Ratao r1;
	Plataforma p1, p2;
	Marcador_Vida* m1;
	Gerenciador_Colisoes gerenciador_colisoes;
	Gerenciador_Grafico gerenciador_grafico;
	Lista<Entidade> lista_entidades;
public:
	Jogo();
	~Jogo();

	void Executar();

	void Inserir_Entidade();
	void Inserir_Colisao();
};

#endif 