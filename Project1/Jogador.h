#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"
#include "Inimigo.h"

class Gerenciador_Grafico;
class Gerenciador_Colisoes;

class Jogador: public Personagem
{
private: 
    int pontos;
    float alturaPulo;
    bool podePular;
    bool empurrado;
public:
    Jogador(float x, float y);
    ~Jogador();

    void Executar(float dT);
    void mover(float dT);

    void reseta_jogador();

    void reseta_velocidade();
    void setEmpurrado(bool emp);

    void Pontua(Inimigo* pI);
    void operator++();

    void setTipo();
};

#endif