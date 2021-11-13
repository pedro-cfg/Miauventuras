#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"

class Gerenciador_Colisoes;

class Jogador: public Personagem
{
private: 
    int pontos;
    float velocidadeX;
    float velocidadeY;
    float velocidadeEscalar;
    float alturaPulo;
    bool podePular;
    
    bool colidiu_cima, colidiu_baixo, colidiu_esquerda, colidiu_direita;
public:
    Jogador(float x, float y);
    ~Jogador();

    void mover(float dT);

    void reseta_colidiu();
    void reseta_velocidade();

    void setColidiuCima(bool colidiu);
    void setColidiuBaixo(bool colidiu);
    void setColidiuDireita(bool colidiu);
    void setColidiuEsquerda(bool colidiu);

    bool getColidiuCima() const;
    bool getColidiuBaixo() const;
    bool getColidiuDireita() const;
    bool getColidiuEsquerda() const;

    void setVelocidadeEscalar(float v);
    float getVelocidadeEscalar() const; 
};

#endif