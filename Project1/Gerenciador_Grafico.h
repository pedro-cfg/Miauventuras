#ifndef _GERENCIADOR_GRAFICO_H
#define _GERENCIADOR_GRAFICO_H

#include "stdafx.h"
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Menu.h"

class Gerenciador_Grafico 
{
private:
	map<string, sf::Texture*> mapa_texturas;
	sf::RenderWindow janela;
	sf::View vista;
	sf::RectangleShape fundo;

	Menu* pM;

	class Marcador_Vida
	{
	private:
		float x;
		float y;
		Jogador* pJogador;
		vector<sf::Texture*> texturas;
		sf::RectangleShape forma_marcador;
	public:
		Marcador_Vida(float x1, float y1);
		~Marcador_Vida();

		void CarregaTextura(string caminho);
		void setJogador(Jogador* pJ);
		void AtualizaMarcador();
		sf::RectangleShape& getforma();
	};

public:
	Gerenciador_Grafico(Menu* pM);
	~Gerenciador_Grafico();

	bool JanelaAberta();
	void RedimensionarVista();
	void AjustarVista(Jogador* jogador);
	void RestaurarVista();
	void EventosJanela(int& estado_jogo);

	void DesenhaTexto(sf::Text* texto);
	void DesenhaForma(sf::RectangleShape& forma);
	void DesenhaTudo(ListaEntidades& lista);
	void MudaFundo(int fase);

	map<string, sf::Texture*> getMapaTexturas() const;
	void InicializaMapaTexturas();

	void LimparTela();

	void FecharJanela();
private:
	Marcador_Vida marcador1;
	//Marcador_Vida marcador2;
public:
	Marcador_Vida* getMarcador();
};

#endif