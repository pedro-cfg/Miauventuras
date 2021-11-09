#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include "stdafx.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"

class Gerenciador_Grafico {
private:
	sf::RenderWindow janela;
	sf::View vista;
public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();

	bool JanelaAberta();
	void RedimensionarVista(sf::RenderWindow& janela, sf::View& vista);
	void Fechar_Redimensionar();
	void Mover_Teclado(Gerenciador_Colisoes* gerenciador, Jogador* jogador);
	void Desenha(Entidade* e1, Entidade* e2, Entidade* e3, Entidade* e4);
};

#endif