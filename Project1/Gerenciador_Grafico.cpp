#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico() :
	janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!"),
	vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(LARGURA_EXIBICAO, ALTURA_EXIBICAO))
{
	sf::RenderWindow janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!");
	sf::View vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(640.f, 360.f));
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{

}

bool Gerenciador_Grafico::JanelaAberta()
{
	return janela.isOpen();
}

void Gerenciador_Grafico::RedimensionarVista()
{
	float razao = (float)janela.getSize().x / (float)janela.getSize().y;

	vista.setSize(ALTURA_EXIBICAO * razao, ALTURA_EXIBICAO);
}

void Gerenciador_Grafico::AjustarVista(Jogador* jogador)
{
	float coordY = jogador->getY();
	float coordX = jogador->getX() + 200.f;
	if (coordY > -380)
		coordY = -380;
	if (coordX < 57)
		coordX = 57;
	vista.setCenter(coordX, coordY);
}

void Gerenciador_Grafico::EventosJanela()
{
	sf::Event event;
	while (janela.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			janela.close();
			break;
		case sf::Event::Resized:
			RedimensionarVista();
			break;
		}
	}
}

void Gerenciador_Grafico::DesenhaForma(sf::RectangleShape& forma)
{
	janela.draw(forma);
}

void Gerenciador_Grafico::DesenhaTudo(Lista<Entidade> lista)
{
	janela.clear(sf::Color(255, 255, 255, 255));
	janela.setView(vista);

	for (int i = 0; i < lista.Quantidade(); i++) {
		Entidade* pE = lista.Buscar(i);
		if (pE != NULL)
			pE->desenhar();
	}

	janela.display();
}

