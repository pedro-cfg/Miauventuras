#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "stdafx.h"
#include "Ente.h"
#include "Lista.h"

class Gerenciador_Grafico;
class Gerenciador_Colisoes;

class Entidade: public Ente 
{
protected:
    float x;
    float y;

    sf::Texture textura;
    sf::RectangleShape forma;

    Gerenciador_Colisoes *gerenciador;
public: 
    Entidade();
    ~Entidade();
    void desenhar();
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    float getAltura() const;
    float getLargura() const;

    void CarregaTextura(string caminho);
    void setGerenciadorColisoes(Gerenciador_Colisoes* ger);
};

#endif 