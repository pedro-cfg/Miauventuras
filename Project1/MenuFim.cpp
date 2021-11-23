#include "MenuFim.h"
#include "Gerenciador_Grafico.h"
#include "Jogo.h"

MenuFim::MenuFim()
{
	linhas_texto = 3;
	vitoria = false;
	InicializaTexto();
}

MenuFim::~MenuFim()
{
}

void MenuFim::Executar(float dT)
{
	if (vitoria)
	{
		texto[1].setString("Vitoria!!!!! =D");
	}
	else
	{
		texto[1].setString("Derrota :(");
	}
	pGG->RestaurarVista();
	imprimir_se();
}

void MenuFim::setVitoria(const bool v)
{
	vitoria = v;
}

void MenuFim::InicializaTexto()
{
	fonte.loadFromFile("Fontes/SIXTY.ttf");
	texto[0].setFont(fonte);
	texto[0].setFillColor(sf::Color::Black);
	texto[0].setString("OJogoDoGato");
	texto[0].setCharacterSize(180);
	texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
	texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
	texto[1].setFont(fonte);
	texto[1].setFillColor(sf::Color::Blue);
	texto[1].setString("");
	texto[1].setCharacterSize(45);
	texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
	texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 20.f, ALTURA_JANELA / 6.f * 3));
	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::Black);
	texto[2].setString("Voltar ao Menu Principal");
	texto[2].setCharacterSize(45);
	texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
	texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 4));
}

void MenuFim::Escolher_Opcao()
{
	if (indice == 2)
	{
		SalvarPontuacao();
		pMaquinaEstados->setEstadoAtual(MENU_PRINCIPAL);
	}
	indice = 1;
	setCorTexto();
}
