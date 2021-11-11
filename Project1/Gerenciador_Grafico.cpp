#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico() :
	janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!"),
	vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(LARGURA_JANELA, ALTURA_JANELA))
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
    float coordY = (float)jogador->getY();
    float coordX = (float)jogador->getX() + 200.f;
    if (coordY > -280)
        coordY = -280;
    if (coordX < 0)
        coordX = 0;
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
    janela.clear();
    janela.setView(vista);

    for (int i = 0; i < lista.Quantidade(); i++) {
        Entidade* pE = lista.Buscar(i);
        if(pE != NULL)
            pE->desenhar();
    }

    janela.display();
}

