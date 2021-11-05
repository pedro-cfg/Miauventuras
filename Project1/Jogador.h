#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"

class Jogador: public Personagem {
private: 
    int pontos;
public:
    Jogador();
    ~Jogador();
};

#endif