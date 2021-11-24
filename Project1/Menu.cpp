#include "stdafx.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "Jogador.h"
#include "Jogo.h"
#include "MenuPlacar.h"

Jogo* Menu::pJogo = NULL;

bool Menu::dois_jogadores = false;
bool Menu::eventoPlacar = true;

void Menu::setPonteiroJogo(Jogo* pJ)
{
	pJogo = pJ;
}

void Menu::setDoisJogadores(bool DJ)
{
	dois_jogadores = DJ;
}

bool Menu::getDoisJogadores()
{
	return dois_jogadores;
}

Menu::Menu() :
	Ente(),
	Estado(),
	linhas_texto(0),
	indice(1)
{

}

Menu::~Menu()
{
}

void Menu::InicializaTexto()
{
}

void Menu::ExecutaEstado(float dT)
{
	this->Executar(dT);
}

void Menu::Executar(float dT)
{
	pGG->RestaurarVista();
	desenhar();
}

void Menu::desenhar()
{
	pGG->DesenhaTexto(texto, linhas_texto);
}

void Menu::Escolher_Opcao()
{
}

float Menu::CalculaTamanho(sf::Text texto)
{
	string frase = texto.getString();
	return (float)(frase.size() * texto.getCharacterSize() / 5);
}

void Menu::opcao_acima()
{
	if (indice > 1)
	{
		texto[indice].setFillColor(sf::Color::Black);
		indice--;
		texto[indice].setFillColor(sf::Color::Blue);
	}
}

void Menu::opcao_abaixo()
{
	if (indice < linhas_texto - 1)
	{
		texto[indice].setFillColor(sf::Color::Black);
		indice++;
		texto[indice].setFillColor(sf::Color::Blue);
	}
}

void Menu::SalvarPontuacao()
{
	string frase[5], n1, n2;
	int pontuacao[5], p1, p2, i, j, tam = 0;
	bool posicionado = false;

	for (int i = 0; i < 5; i++) {
		pontuacao[i] = 0; frase[i] = "...";
	}

	fstream arquivo;
	arquivo.open("Persistencia/placar.bin", ios::binary | ios::in);

	for (i = 0; i < 5; i++) {
		arquivo.read((char*)&tam, sizeof(tam));
		frase[i].resize(tam);
		arquivo.read((char*)&frase[i][0], tam);
		arquivo.read((char*)&pontuacao[i], sizeof(int));
	}

	arquivo.close();

	arquivo.open("Persistencia/placar.bin", ios::binary | ios::out | ios::trunc);

	n1 = pJogo->getJogador1()->getNome();
	p1 = pJogo->getJogador1()->getPontuacao();
	n2 = pJogo->getJogador2()->getNome();
	p2 = pJogo->getJogador2()->getPontuacao();

	for (i = 0; i < 5 && !posicionado; i++) {
		if (p1 >= pontuacao[i]) {
			for (j = 4; j > i; j--) {
				pontuacao[j] = pontuacao[j - 1];
				frase[j] = frase[j - 1];
			}
			pontuacao[j] = p1;
			frase[j] = n1;
			posicionado = true;
		}
	}

	posicionado = false;
	for (i = 0; i < 5 && !posicionado; i++) {
		if (p2 >= pontuacao[i]) {
			for (j = 4; j > i; j--) {
				pontuacao[j] = pontuacao[j - 1];
				frase[j] = frase[j - 1];
			}
			pontuacao[j] = p2;
			frase[j] = n2;
			posicionado = true;
		}
	}


	for (i = 0; i < 5; i++) {
		tam = frase[i].size();
		arquivo.write((char*)&tam, sizeof(tam));
		arquivo.write((char*)&frase[i][0], tam);
		arquivo.write((char*)&pontuacao[i], sizeof(int));
	}

	arquivo.close();
}

void Menu::setCorTexto()
{
	texto[0].setFillColor(sf::Color::Black);
	texto[1].setFillColor(sf::Color::Blue);
	for (int i = 2; i < 7; i++)
		texto[i].setFillColor(sf::Color::Black);
}
