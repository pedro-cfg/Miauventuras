#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico() :
	janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!"),
	vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(640.f, 360.f))
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

    vista.setSize(ALTURA_JANELA * razao, ALTURA_JANELA);
}

void Gerenciador_Grafico::AjustarVista(Jogador* jogador)
{
    vista.setCenter((float)jogador->getX(), (float)jogador->getY());
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

void Gerenciador_Grafico::DesenhaTudo(Entidade* e1, Entidade* e2, Entidade* e3, Entidade* e4, Entidade* e5)
{
    janela.clear();
    janela.setView(vista);

    e1->desenhar();
    e2->desenhar();
    e3->desenhar();
    e4->desenhar();
    e5->desenhar();

    janela.display();
}

