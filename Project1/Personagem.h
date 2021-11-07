#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

//#include "Entidade.h"
#include "stdafx.h"

class Personagem//: public Entidade 
{
protected: 
    int num_vidas;
    sf::Texture textura;
    sf::RectangleShape forma;
public:
    Personagem();
    ~Personagem();

    sf::RectangleShape getForma() const;

    void mover(float dx, float dy);
};

#endif