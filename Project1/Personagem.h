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
    void setVelocidadeEscalar(float v);
    float getVelocidadeEscalar() const;

    /*Sobrecarga de operador -- -> responsável pelo dano*/
    void operator--();

    bool Morreu() const;

    virtual void mover(float dT){}
    virtual void Executar(float dT){}

    virtual void reseta_velocidade(){}
    void reseta_colidiu();

    void setVelocidadeY(float v);
    void setVelocidadeX(float v);

    float getContador() const;

    void setColidiuCima(bool colidiu);
    void setColidiuBaixo(bool colidiu);
    void setColidiuDireita(bool colidiu);
    void setColidiuEsquerda(bool colidiu);
};

#endif