#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"
#include "stdafx.h"

class Personagem: public Entidade 
{
protected: 
    int vidas;
    float velocidadeEscalar;

    float contador_tempo;
public:
    Personagem();
    ~Personagem();

    int getVidas() const;

    void sofreDano();
    void operator--();

    virtual void mover(float dT);
    void setVelocidadeEscalar(float v);
    float getVelocidadeEscalar() const;

    void Atualiza_Contador(float dT, bool zera = false);
    float getContador();
};

#endif