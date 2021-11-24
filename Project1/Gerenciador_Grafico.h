#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include "stdafx.h"
#include "Jogador.h"
#include "Jogador1.h"
#include "Jogador2.h"
#include "ListaEntidades.h"
#include "MenuNome.h"
#include "Menu.h"
#include "MaquinaEstados.h"

class Gerenciador_Grafico 
{
private:
	/*Mapa de texturas, parametrizado com <caminho para o arquivo, ponteiro para a textura>*/
	map<string, sf::Texture*> mapa_texturas;

	sf::RenderWindow janela;
	sf::View vista;
	sf::RectangleShape fundo;
	sf::Color cor_fundo;

	/*Classe gráfica aninhada - marcador de vida*/
	class Marcador_Vida
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
		sf::RectangleShape& getforma();
	};

public:
	Gerenciador_Grafico();
	~Gerenciador_Grafico();

	bool JanelaAberta();
	void RedimensionarVista();
	void AjustarVista(Jogador1* pJ1, Jogador2* pJ2);
	void RestaurarVista();
	void EventosJanela(MaquinaEstados* pMaqEstados);
	void AtualizarTela();
	void FecharJanela();

	void DesenhaTexto(sf::Text* texto, int tamanho);
	void DesenhaForma(sf::RectangleShape& forma);
	void DesenhaTudo(ListaEntidades& lista, Jogador1* pJ1, Jogador2* pJ2 = NULL);
	void MudaFundo(int fase);
	void setCorFundo(int R, int G, int B);

	map<string, sf::Texture*> getMapaTexturas() const;
	void InicializaMapaTexturas();

private:
	/*Marcadores de vida dos jogadores 1 e 2*/
	Marcador_Vida marcador1;
	Marcador_Vida marcador2;
public:
	Marcador_Vida* getMarcador1();
	Marcador_Vida* getMarcador2();
};

#endif