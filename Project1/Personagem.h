#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.h"
#include "stdafx.h"

class Personagem: public Entidade 
{
protected: 
    int num_vidas;
public:
    Personagem();
    ~Personagem();
};

#endif