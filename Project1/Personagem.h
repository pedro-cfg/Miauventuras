#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"
#include "stdafx.h"

class Personagem: public Entidade 
{
protected: 
    int vidas;
    float velocidadeEscalar;
    float velocidadeX;
    float velocidadeY;
    bool colidiu_cima, colidiu_baixo, colidiu_esquerda, colidiu_direita;

public:
    Personagem();
    ~Personagem();

    int getVidas() const;
    void setVidas(int v);

    void sofreDano();
    void operator--();

    virtual void mover(float dT);
    void setVelocidadeEscalar(float v);
    float getVelocidadeEscalar() const;
    virtual void reseta_velocidade();

    void setVelocidadeY(float v);
    void setVelocidadeX(float v);

    float getContador();

    void setColidiuCima(bool colidiu);
    void setColidiuBaixo(bool colidiu);
    void setColidiuDireita(bool colidiu);
    void setColidiuEsquerda(bool colidiu);

    bool getColidiuCima() const;
    bool getColidiuBaixo() const;
    bool getColidiuDireita() const;
    bool getColidiuEsquerda() const;

    void reseta_colidiu();
};

#endif