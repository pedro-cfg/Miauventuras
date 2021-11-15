#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include "stdafx.h"
//#include "Entidade.h"
#include "Jogador.h"
#include "ListaEntidades.h"

class Gerenciador_Grafico 
{
private:
	sf::RenderWindow janela;
	sf::View vista;
	sf::Texture textura_fundo;
	sf::RectangleShape fundo;

	class Marcador_Vida
	{
	private:
		float x;
		float y;
		Jogador* pJogador;
		sf::Texture textura_1;
		sf::Texture textura_2;
		sf::Texture textura_3;
		sf::RectangleShape forma_marcador;
	public:
		Marcador_Vida(float x1, float y1, Jogador* pJ);
		~Marcador_Vida();

		void AtualizaMarcador();
		sf::RectangleShape& getforma();
	};

public:
	Gerenciador_Grafico(Jogador* pJ);
	~Gerenciador_Grafico();

	bool JanelaAberta();
	void RedimensionarVista();
	void AjustarVista(Jogador* jogador);
	void EventosJanela();

	void DesenhaForma(sf::RectangleShape& forma);
	void DesenhaTudo(ListaEntidades& lista);

private:
	Marcador_Vida marcador1;
	//Marcador_Vida marcador2;
public:
	Marcador_Vida* getMarcador();
};

#endif