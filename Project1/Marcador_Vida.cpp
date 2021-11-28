#include "Marcador_Vida.h"
#include "Gerenciador_Grafico.h"

Marcador_Vida::Marcador_Vida(float x0, float y0) :
	x(x0), y(y0), pJogador(NULL)
{
	CarregaTextura("Texturas/Numeros/1.png");
	CarregaTextura("Texturas/Numeros/2.png");
	CarregaTextura("Texturas/Numeros/3.png");
	CarregaTextura("Texturas/Numeros/4.png");
	CarregaTextura("Texturas/Numeros/5.png");
	CarregaTextura("Texturas/Numeros/6.png");
	CarregaTextura("Texturas/Numeros/7.png");

	forma_marcador.setSize((sf::Vector2f)texturas[0]->getSize());
	forma_marcador.setTexture(texturas[0]);
	forma_marcador.setOrigin(forma_marcador.getSize() / 2.0f);
	forma_marcador.setPosition(sf::Vector2f(x, y));
}

Marcador_Vida::~Marcador_Vida()
{
	/*Desaloca vector de texturas*/
	int tam = (int)texturas.size();
	for (int i = 0; i < tam; i++)
	{
		if (texturas[i] != NULL)
		{
			delete texturas[i];
		}
	}
	texturas.clear();
}

void Marcador_Vida::CarregaTextura(string caminho)
{
	sf::Texture* pTextura = new sf::Texture();
	pTextura->loadFromFile(caminho);

	texturas.push_back(pTextura);
}

void Marcador_Vida::setJogador(Jogador* pJ)
{
	pJogador = pJ;
}

void Marcador_Vida::AtualizaMarcador(sf::View* vista)
{
	if (pJogador)
	{
		float coordX = vista->getCenter().x;
		float coordY = vista->getCenter().y;
		forma_marcador.setPosition(coordX + x, coordY + y);
		int vidas = pJogador->getVidas();

		if (0 < vidas && vidas <= 7)
		{
			forma_marcador.setTexture(texturas[vidas - 1]);
		}
	}
}

sf::RectangleShape& Marcador_Vida::getForma()
{
	return forma_marcador;
}
