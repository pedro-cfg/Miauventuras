#include "stdafx.h"
#include "Jogador.h"
#include "Aranha.h"
#include "Lagartixa.h"
#include "Ratao.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!");
    
    Jogador j1;
    Aranha a1;
    Lagartixa l1;
    Ratao r1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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
        
        window.clear();
        window.draw(j1.getForma());
        window.draw(a1.getForma());
        window.draw(l1.getForma());
        window.draw(r1.getForma());
        window.display();
    }

    return 0;
}