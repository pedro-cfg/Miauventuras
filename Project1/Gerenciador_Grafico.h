#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include "stdafx.h"
#include "Jogador.h"
#include "Jogador1.h"
#include "Jogador2.h"
#include "ListaEntidades.h"
#include "Menu.h"
#include "MaquinaEstados.h"

class Gerenciador_Grafico 
{
private:
	map<string, sf::Texture*> mapa_texturas;
	sf::RenderWindow janela;
	sf::View vista;
	sf::RectangleShape fundo;

	class Marcador_Vida
	{
	private:
		float x;
		float y;
		Jogador* pJogador;
		vector<sf::Texture*> texturas;
		sf::RectangleShape forma_marcador;
	public:
		Marcador_Vida(float x0, float y0);
		~Marcador_Vida();

		void CarregaTextura(string caminho);
		void setJogador(Jogador* pJ);
		void AtualizaMarcador(sf::View* vista);
		sf::RectangleShape& getforma();
	};

public:
	Gerenciador_Grafico(Menu* pM);
	~Gerenciador_Grafico();

	bool JanelaAberta();
	void RedimensionarVista();
	void AjustarVista(Jogador1* pJ1, Jogador2* pJ2 = NULL);
	void RestaurarVista();
	void EventosJanela(MaquinaEstados* pMaqEstados);

	void DesenhaTexto(sf::Text* texto, int tamanho);
	void DesenhaForma(sf::RectangleShape& forma);
	void DesenhaTudo(ListaEntidades& lista, Jogador1* pJ1, Jogador2* pJ2 = NULL);
	void MudaFundo(int fase);

	map<string, sf::Texture*> getMapaTexturas() const;
	void InicializaMapaTexturas();

	void AtualizarTela();

	void FecharJanela();
private:
	Marcador_Vida marcador1;
	Marcador_Vida marcador2;
public:
	Marcador_Vida* getMarcador1();
	Marcador_Vida* getMarcador2();
};

#endif