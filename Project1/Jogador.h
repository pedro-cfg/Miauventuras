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
public:
    Jogador(float x, float y);
    ~Jogador();

    void mover(float dT, Gerenciador_Colisoes* gerenciador);
};

#endif