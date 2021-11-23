#include "MenuPlacar.h"
#include "Gerenciador_Grafico.h"

MenuPlacar::MenuPlacar() :
	Menu()
{
	InicializaTexto();
	linhas_texto = 7;
}

MenuPlacar::~MenuPlacar()
{
	for (int i = 0; i < 5; i++)
	{
		placar[i] = "";
	}
}

void MenuPlacar::InicializaTexto()
{
	setPlacar();
}

void MenuPlacar::Escolher_Opcao()
{
	if (indice == 6)
	{
		pMaquinaEstados->setEstadoAtual(MENU_PRINCIPAL);
	}
	indice = 1;
	setCorTexto();
}

void MenuPlacar::Executar(float dT)
{
	setPlacar();
	pGG->RestaurarVista();
	imprimir_se();
}

void MenuPlacar::setPlacar()
{
	if (eventoPlacar) {
		RecuperarPontuacao();

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

		eventoPlacar = false;
	}
}

void MenuPlacar::RecuperarPontuacao()
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
