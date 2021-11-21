#include "stdafx.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "Jogador.h"

//Menu::Menu(float largura, float altura, FasePrimeira* pFase) :
//	Ente(), 
//	pF(pFase)
//{
//	InicializaTexto(largura, altura);
//}

Menu::Menu(int* estado, bool* dois_j) :
	Ente(),
	estado_jogo(estado),
	dois_jogadores(dois_j),
	estado_menu(0),
	tamanho_texto(5),
	inicializar(true),
	indice(1),
	pJ1(NULL),
	pJ2(NULL)
{
}

Menu::~Menu() {
	for (int i = 0; i < 5; i++) {
		placar[i] = "";
	}
	//delete placar;
}

void Menu::setJogadores(Jogador* pJog1, Jogador* pJog2)
{
	pJ1 = pJog1;
	pJ2 = pJog2;
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
	case 3: //Input Nome
		indice = 1;
		fonte.loadFromFile("Fontes/SIXTY.ttf");
		texto[0].setFont(fonte);
		texto[0].setFillColor(sf::Color::Black);
		texto[0].setString("Voce fez " + to_string(pJ1->getPontuacao()) + " Pontos!");
		texto[0].setCharacterSize(180);
		texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
		texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
		texto[1].setFont(fonte);
		texto[1].setFillColor(sf::Color::Blue);
		texto[1].setString("Jogador 1, informe seu nome:");
		texto[1].setCharacterSize(45);
		texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
		texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
		texto[2].setFont(fonte);
		texto[2].setFillColor(sf::Color::Black);
		texto[2].setString("");
		texto[2].setCharacterSize(45);
		texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f - 30.f, ALTURA_JANELA / 6.f * 4));
		break;
	case 4: //Menu Numero de Jogadores
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
		texto[1].setString("1 Jogador");
		texto[1].setCharacterSize(45);
		texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
		texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
		texto[2].setFont(fonte);
		texto[2].setFillColor(sf::Color::Black);
		texto[2].setString("2 Jogadores");
		texto[2].setCharacterSize(45);
		texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
		texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 4));
		texto[3].setFont(fonte);
		texto[3].setFillColor(sf::Color::Black);
		texto[3].setString("Voltar");
		texto[3].setCharacterSize(45);
		texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
		texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 5));
		break;
	case 5: //Menu Placar
		indice = 1;
		fonte.loadFromFile("Fontes/SIXTY.ttf");
		texto[0].setFont(fonte);
		texto[0].setFillColor(sf::Color::Black);
		texto[0].setString("Placar");
		texto[0].setCharacterSize(180);
		texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
		texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
		texto[1].setFont(fonte);
		texto[1].setFillColor(sf::Color::Blue);
		texto[1].setString(placar[0]);
		texto[1].setCharacterSize(45);
		texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
		texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 2));
		texto[2].setFont(fonte);
		texto[2].setFillColor(sf::Color::Black);
		texto[2].setString(placar[1]);
		texto[2].setCharacterSize(45);
		texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
		texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
		texto[3].setFont(fonte);
		texto[3].setFillColor(sf::Color::Black);
		texto[3].setString(placar[2]);
		texto[3].setCharacterSize(45);
		texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
		texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 4));
		texto[4].setFont(fonte);
		texto[4].setFillColor(sf::Color::Black);
		texto[4].setString(placar[3]);
		texto[4].setCharacterSize(45);
		texto[4].setOrigin(sf::Vector2f(CalculaTamanho(texto[4]), 0.f));
		texto[4].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 5));
		texto[5].setFont(fonte);
		texto[5].setFillColor(sf::Color::Black);
		texto[5].setString(placar[4]);
		texto[5].setCharacterSize(45);
		texto[5].setOrigin(sf::Vector2f(CalculaTamanho(texto[5]), 0.f));
		texto[5].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 6));
		texto[6].setFont(fonte);
		texto[6].setFillColor(sf::Color::Black);
		texto[6].setString("Voltar");
		texto[6].setCharacterSize(45);
		texto[6].setOrigin(sf::Vector2f(CalculaTamanho(texto[6]), 0.f));
		texto[6].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 7));
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
			pJ1->reseta_jogador(true, true, true);
			pJ2->reseta_jogador(true, true, true);
			estado_menu = 4;
			tamanho_texto = 4;
		}
		else if (estado_menu == 1) {
			estado_menu = 0;
			tamanho_texto = 5;
			*estado_jogo = 1;
		}
		else if (estado_menu == 2) {
			estado_menu = 0;
			tamanho_texto = 5;
			*estado_jogo = 7;
		}
		else if (estado_menu == 3) {
			if (pJ1->getNome() == "") {
				pJ1->setNome(texto[2].getString());
				if (*dois_jogadores) {
					inicializar = false;
					texto[0].setString("Voce fez " + to_string(pJ2->getPontuacao()) + " Pontos!");
					texto[1].setString("Jogador 2, informe seu nome:");
					texto[2].setString("");
				}
				else {
					estado_menu = 0;
					tamanho_texto = 5;
					inicializar = true;
					SalvarPontuacao();
				}
			}
			else {
				pJ2->setNome(texto[2].getString());
				estado_menu = 0;
				tamanho_texto = 5;
				inicializar = true;
				SalvarPontuacao();
			}
		}
		else if (estado_menu == 4) {
			*dois_jogadores = false;
			estado_menu = 1;
		}
		break;
	case 2:
		if (estado_menu == 0) {
			*estado_jogo = 3;
			inicializar = true;
		}
		else if (estado_menu == 1) {
			estado_menu = 0;
			inicializar = true;
			tamanho_texto = 5;
			*estado_jogo = 2;
		}
		else if (estado_menu == 2) {
			*estado_jogo = 5;
			texto[2].setString("Jogo Salvo!");
			texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 125.f, ALTURA_JANELA / 6.f * 4));
		}
		else if (estado_menu == 4) {
			*dois_jogadores = true;
			inicializar = true;
			estado_menu = 1;
		}
		break;
	case 3:
		if (estado_menu == 0) {
			RecuperarPontuacao();
			estado_menu = 5;
			inicializar = true;
			tamanho_texto = 7;
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
			*estado_jogo = 6;
		}
		else if (estado_menu == 4) {
			inicializar = true;
			estado_menu = 0;
			tamanho_texto = 5;
		}
		break;
	case 4:
		*estado_jogo = -1;
		break;
	case 6:
		estado_menu = 0;
		inicializar = true;
		tamanho_texto = 5;
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

const int Menu::getEstado() const
{
	return estado_menu;
}

void Menu::incluiTexto(char letra)
{
	string frase = texto[2].getString();
	frase += letra;
	texto[2].setString(frase);
}

void Menu::retiraTexto()
{
	string frase = texto[2].getString();
	if (frase != "")
		frase.pop_back();
	texto[2].setString(frase);
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

	n1 = pJ1->getNome();
	p1 = pJ1->getPontuacao();
	n2 = pJ2->getNome();
	p2 = pJ2->getPontuacao();

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

	pJ1->reseta_jogador(true, true, true);
	pJ2->reseta_jogador(true, true, true);
}

void Menu::RecuperarPontuacao()
{
	string frase[5];
	int pontuacao[5], tam = 0;

	for (int i = 0; i < 5; i++) {
		pontuacao[i] = 0; frase[i] = "...";
	}

	fstream arquivo;
	arquivo.open("Persistencia/placar.bin", ios::binary | ios::in);

	for (int i = 0; i < 5; i++) {
		arquivo.read((char*)&tam, sizeof(tam));
		frase[i].resize(tam);
		arquivo.read((char*)&frase[i][0], tam);
		arquivo.read((char*)&pontuacao[i], sizeof(pontuacao[i]));
		placar[i] = frase[i] + " - " + to_string(pontuacao[i]) + " Pontos";
	}

	arquivo.close();
}
