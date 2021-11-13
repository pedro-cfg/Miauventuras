#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"
#include "stdafx.h"

class Personagem: public Entidade 
{
protected: 
    int vidas;
public:
    Personagem();
    ~Personagem();

    int getVidas() const;

    void sofreDano();
    void operator--();

};

#endif