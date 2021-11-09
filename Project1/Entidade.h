#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "Ente.h"
#include "stdafx.h"

class Entidade: public Ente {
protected:
    /*int x;
    int y;*/
    sf::Texture textura;
    sf::RectangleShape forma;
public: 
    Entidade();
    ~Entidade();
    virtual sf::RectangleShape getForma() const;
    sf::Vector2f getPosicao();
};

#endif 