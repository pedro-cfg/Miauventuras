#include "stdafx.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"

//Menu::Menu(float largura, float altura, FasePrimeira* pFase) :
//	Ente(), 
//	pF(pFase)
//{
//	InicializaTexto(largura, altura);
//}

Menu::Menu(float largura, float altura, int* estado):
	Ente(),
	estado_jogo(estado),
	estado_menu(0),
	tamanho_texto(5),
	inicializar(true),
	indice(1)
{
}

Menu::~Menu() {

}

void Menu::InicializaTexto()
{
	switch (estado_menu)
	{
	case 0: //Menu Principal
		indice = 1;
		fonte.loadFromFile("Fontes/SIXTY.ttf");
		texto[0].setFont(fonte);
		texto[0].setFillColor(sf::Color::Black);
		texto[0].setString("OJogoDoGato");
		texto[0].setCharacterSize(180);
		texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
		texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
		texto[1].setFont(fonte);
		texto[1].setFillColor(sf::Color::Blue);
		texto[1].setString("Novo Jogo");
		texto[1].setCharacterSize(45);
		texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
		texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
		texto[2].setFont(fonte);
		texto[2].setFillColor(sf::Color::Black);
		texto[2].setString("Carregar");
		texto[2].setCharacterSize(45);
		texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
		texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 4));
		texto[3].setFont(fonte);
		texto[3].setFillColor(sf::Color::Black);
		texto[3].setString("Placar");
		texto[3].setCharacterSize(45);
		texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
		texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 5));
		texto[4].setFont(fonte);
		texto[4].setFillColor(sf::Color::Black);
		texto[4].setString("Sair");
		texto[4].setCharacterSize(45);
		texto[4].setOrigin(sf::Vector2f(CalculaTamanho(texto[4]), 0.f));
		texto[4].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 6));
		break;
	case 1: //Escolha de Fases
		indice = 1;
		fonte.loadFromFile("Fontes/SIXTY.ttf");
		texto[0].setFont(fonte);
		texto[0].setFillColor(sf::Color::Black);
		texto[0].setString("OJogoDoGato");
		texto[0].setCharacterSize(180);
		texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
		texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
		texto[1].setFont(fonte);
		texto[1].setFillColor(sf::Color::Blue);
		texto[1].setString("Iniciar Fase 1");
		texto[1].setCharacterSize(45);
		texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
		texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
		texto[2].setFont(fonte);
		texto[2].setFillColor(sf::Color::Black);
		texto[2].setString("Iniciar Fase 2");
		texto[2].setCharacterSize(45);
		texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
		texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 4));
		texto[3].setFont(fonte);
		texto[3].setFillColor(sf::Color::Black);
		texto[3].setString("Voltar");
		texto[3].setCharacterSize(45);
		texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
		texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 5));
		break;
	case 2: //Menu de Pausa
		indice = 1;
		fonte.loadFromFile("Fontes/SIXTY.ttf");
		texto[0].setFont(fonte);
		texto[0].setFillColor(sf::Color::Black);
		texto[0].setString("OJogoDoGato");
		texto[0].setCharacterSize(180);
		texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
		texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
		texto[1].setFont(fonte);
		texto[1].setFillColor(sf::Color::Blue);
		texto[1].setString("Continuar");
		texto[1].setCharacterSize(45);
		texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
		texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
		texto[2].setFont(fonte);
		texto[2].setFillColor(sf::Color::Black);
		texto[2].setString("Salvar");
		texto[2].setCharacterSize(45);
		texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
		texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 4));
		texto[3].setFont(fonte);
		texto[3].setFillColor(sf::Color::Black);
		texto[3].setString("Voltar para o Menu Principal");
		texto[3].setCharacterSize(45);
		texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
		texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 5));
		break;
	case 3: //Placar
		break;
	}

}

void Menu::Executar(float dT)
{
	if (inicializar) {
		InicializaTexto();
		pGG->RestaurarVista();
		inicializar = false;
	}
	imprimir_se();
}

void Menu::imprimir_se()
{
	pGG->DesenhaTexto(texto, tamanho_texto);
}

void Menu::setTamanhoTexto(int tam)
{
	tamanho_texto = tam;
}

void Menu::setEstadoMenu(int estado)
{
	estado_menu = estado;
}

void Menu::setInicializar(bool ini)
{
	inicializar = ini;
}

void Menu::Escolher_Opcao()
{
	switch (indice)
	{
	case 1:
		inicializar = true;
		if (estado_menu == 0) {
			estado_menu = 1;
			tamanho_texto = 4;
		}
		else if (estado_menu == 1) {
			estado_menu = 0;
			tamanho_texto = 5;
			estado_jogo = 1;
		}
		else if (estado_menu == 2) {
			estado_menu = 0;
			tamanho_texto = 5;
			estado_jogo = 7;
		}
		break;
	case 2:
		if (estado_menu == 0) {
			estado_jogo = 3;
			inicializar = true;
		}
		else if (estado_menu == 1) {
			estado_menu = 0;
			inicializar = true;
			tamanho_texto = 5;
			estado_jogo = 2;
		}
		else if (estado_menu == 2) {
			estado_jogo = 5;
			texto[2].setString("Jogo Salvo!");
			texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 125.f, ALTURA_JANELA / 6.f * 4));
		}
		break;
	case 3:
		if (estado_menu == 0) {
			//Placar
		}
		else if (estado_menu == 1) {
			estado_menu = 0;
			inicializar = true;
			tamanho_texto = 5;
		}
		else if (estado_menu == 2) {
			estado_menu = 0;
			inicializar = true;
			tamanho_texto = 5;
			estado_jogo = 6;
		}
		break;
	case 4:
		estado_jogo = -1;
		break;
	default:
		break;
	}
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
	if (indice < tamanho_texto - 1)
	{
		texto[indice].setFillColor(sf::Color::Black);
		indice++;
		texto[indice].setFillColor(sf::Color::Blue);
	}
}