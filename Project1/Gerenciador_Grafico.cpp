#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico() :
	janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!"),
	vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(640.f, 360.f))
{
	sf::RenderWindow janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!");
	sf::View vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(640.f, 360.f));
}

Gerenciador_Grafico::~Gerenciador_Grafico() {

}

bool Gerenciador_Grafico::JanelaAberta()
{
	return janela.isOpen();
}

void Gerenciador_Grafico::RedimensionarVista(sf::RenderWindow& janela, sf::View& vista)
{
    float razao = (float)janela.getSize().x / (float)janela.getSize().y;

    vista.setSize(ALTURA_JANELA * razao, ALTURA_JANELA);
}

void Gerenciador_Grafico::Fechar_Redimensionar()
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
            RedimensionarVista(janela, vista);
            break;
        }
    }
}

void Gerenciador_Grafico::Mover_Teclado(Gerenciador_Colisoes* gerenciador, Jogador* jogador)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (!gerenciador->getColidiuDireita())
            jogador->mover(0.1f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (!gerenciador->getColidiuEsquerda())
            jogador->mover(-0.1f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (!gerenciador->getColidiuCima())
            jogador->mover(0.f, -0.1f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (!gerenciador->getColidiuBaixo())
            jogador->mover(0.f, 0.1f);
    }
}

void Gerenciador_Grafico::Desenha(Entidade* e1, Entidade* e2, Entidade* e3, Entidade* e4)
{
    vista.setCenter(e1->getPosicao());
    janela.clear();
    janela.setView(vista);
    janela.draw(e1->getForma());
    janela.draw(e2->getForma());
    janela.draw(e3->getForma());
    janela.draw(e4->getForma());
    janela.display();
}

