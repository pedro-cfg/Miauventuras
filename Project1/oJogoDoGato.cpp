#include "stdafx.h"
#include "Jogador.h"
#include "Aranha.h"
#include "Lagartixa.h"
#include "Ratao.h"

void RedimensionarVista(sf::RenderWindow& janela, sf::View& vista)
{
    float razao = (float)janela.getSize().x / (float)janela.getSize().y;

    vista.setSize(ALTURA_JANELA * razao, ALTURA_JANELA);
}

int main() 
{
    sf::RenderWindow janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!");
    sf::View vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(640.f, 360.f));
    
    Jogador j1;
    Aranha a1;
    Lagartixa l1;
    Ratao r1;

    while (janela.isOpen())
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
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            j1.mover(1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            j1.mover(-1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            j1.mover(0.f, -1.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            j1.mover(0.f, 1.f);
        }
        
        vista.setCenter(j1.getPosicao());
        janela.clear();
        janela.setView(vista);
        janela.draw(j1.getForma());
        janela.draw(a1.getForma());
        janela.draw(l1.getForma());
        janela.draw(r1.getForma());
        janela.display();
    }

    return 0;
}