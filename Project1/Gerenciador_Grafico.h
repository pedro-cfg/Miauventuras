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
#include "Marcador_Vida.h"

class Gerenciador_Grafico 
{
private:
	/*Mapa de texturas, parametrizado com <caminho para o arquivo, ponteiro para a textura>*/
	map<string, sf::Texture*> mapa_texturas;

	sf::RenderWindow janela;
	sf::View vista;
	sf::RectangleShape fundo;
	sf::Color cor_fundo;

	Marcador_Vida marcador1;
	Marcador_Vida marcador2;
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

	Marcador_Vida* getMarcador1();
	Marcador_Vida* getMarcador2();
};

#endif