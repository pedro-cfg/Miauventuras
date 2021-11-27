#ifndef _MARCADOR_VIDA_H_
#define _MARCADOR_VIDA_H_

#include "stdafx.h"
#include "Ente.h"
#include "Jogador.h"

class Marcador_Vida : public Ente
{
private:
	float x;
	float y;
	/*Ponteiro para o jogador ao qual o marcador se refere*/
	Jogador* pJogador;
	/*Vector com as texturas do marcador*/
	vector<sf::Texture*> texturas;
	sf::RectangleShape forma_marcador;
public:
	Marcador_Vida(float x0, float y0);
	~Marcador_Vida();

	void CarregaTextura(string caminho);
	void setJogador(Jogador* pJ);
	void AtualizaMarcador(sf::View* vista);
	void desenhar();
};

#endif