#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include "stdafx.h"
#include "Gerenciador_Colisoes.h"
#include "Entidade.h"
#include "Jogador.h"

class Gerenciador_Grafico 
{
private:
	sf::RenderWindow janela;
	sf::View vista;
public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();

	bool JanelaAberta();
	void RedimensionarVista();
	void AjustarVista(Jogador* jogador);
	void EventosJanela();

	void DesenhaForma(sf::RectangleShape& forma);
	void DesenhaTudo(Entidade* e1, Entidade* e2, Entidade* e3, Entidade* e4, Entidade* e5);
};

#endif