#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.h"
#include "Inimigo.h"

class Gerenciador_Colisoes;

class Jogador: public Personagem
{
private: 
    int pontos;
    float alturaPulo;
    bool podePular;
    float velocidadeX;
    float velocidadeY;
    float contador_tempo;
    bool colidiu_cima, colidiu_baixo, colidiu_esquerda, colidiu_direita;
public:
    Jogador(float x, float y);
    ~Jogador();

    void Executar(float dT);
    void mover(float dT);

    void reseta_colidiu();
    void reseta_velocidade();
    void setVelocidadeY(float v);

    void setColidiuCima(bool colidiu);
    void setColidiuBaixo(bool colidiu);
    void setColidiuDireita(bool colidiu);
    void setColidiuEsquerda(bool colidiu);

    bool getColidiuCima() const;
    bool getColidiuBaixo() const;
    bool getColidiuDireita() const;
    bool getColidiuEsquerda() const;

    void Pontua(Inimigo* pI);
    void operator++();

    void Atualiza_Contador(float dT, bool zera = false);
    float getContador();
};

#endif