#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"
#include "stdafx.h"
#include "Marcador_Vida.h"

class Personagem: public Entidade 
{
protected: 
    int vidas;
public:
    Personagem();
    ~Personagem();

    int getVidas() const;

    void operator--();

};

#endif