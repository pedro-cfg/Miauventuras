#include "stdafx.h"
#include "Jogador.h"
#include "Aranha.h"
#include "Lagartixa.h"
#include "Ratao.h"
#include "Gerenciador_Colisoes.h"

int main() 
{
    sf::RenderWindow window(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!");
    
    Jogador j1;
    Aranha a1;
    Lagartixa l1;
    Ratao r1;
    Gerenciador_Colisoes gerenciador_colisoes(&j1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        gerenciador_colisoes.Reset_Checagem();
        gerenciador_colisoes.Checa_Colisao(&a1);
        gerenciador_colisoes.Checa_Colisao(&l1);
        gerenciador_colisoes.Checa_Colisao(&r1);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if(!gerenciador_colisoes.getColidiuDireita())
                j1.mover(0.1f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(!gerenciador_colisoes.getColidiuEsquerda())
                j1.mover(-0.1f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if(!gerenciador_colisoes.getColidiuCima())
                j1.mover(0.f, -0.1f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(!gerenciador_colisoes.getColidiuBaixo())
                j1.mover(0.f, 0.1f);
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