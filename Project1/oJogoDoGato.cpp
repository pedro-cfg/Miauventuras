#include "stdafx.h"
#include "Jogador.h"
#include "Aranha.h"
#include "Lagartixa.h"
#include "Ratao.h"
#include "Gerenciador_Colisoes.h"

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
    
    Gerenciador_Colisoes gerenciador_colisoes(&j1);
    gerenciador_colisoes.InserirInimigo(&a1);
    gerenciador_colisoes.InserirInimigo(&l1);
    gerenciador_colisoes.InserirInimigo(&r1);

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
        
        gerenciador_colisoes.Checa_Colisao();

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