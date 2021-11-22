#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "stdafx.h"
#include "Personagem.h"
#include "Inimigo.h"

class Gerenciador_Grafico;
class Gerenciador_Colisoes;

class Jogador: public Personagem
{
private: 
    string nome;
    int pontos;
    float alturaPulo;
    bool podePular;
    bool empurrado;
    bool venceu;

    int fase;
public:
    Jogador();
    ~Jogador();

    void Executar(float dT);
    void mover(float dT);
    virtual bool mover_esq();
    virtual bool mover_dir();
    virtual bool pular();

    void reseta_jogador(const bool resetaPontos = false, const bool resetaVidas = false, const bool resetaNome = false);

    void reseta_velocidade();
    void setEmpurrado(bool emp);

    void setVenceu(const bool v);
    bool getVenceu() const;

    bool Morreu() const;

    void Pontua(Inimigo* pI);
    void operator++();

    void setTipo();

    void setFase(int f);
    const int getFase() const;

    void setPontuacao(int pont);
    const int getPontuacao() const;
    void setNome(string n);
    const string getNome() const;
};

#endif