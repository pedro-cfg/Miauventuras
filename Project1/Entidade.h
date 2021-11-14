#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "stdafx.h"
#include "Ente.h"

class Gerenciador_Colisoes;
class ListaEntidades;

class Entidade: public Ente 
{
protected:
    float x;
    float y;

    sf::Texture textura;
    sf::RectangleShape forma;

    static Gerenciador_Colisoes* pGC;
    static ListaEntidades* pLista;

    string tipo;

    float contador_tempo;

public: 
    Entidade();
    ~Entidade();
    void desenhar();
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    float getAltura() const;
    float getLargura() const;

    void CarregaTextura(string caminho);
    
    static void setGerenciadorColisoes(Gerenciador_Colisoes* pG);
    static void setPonteiroLista(ListaEntidades* pL);

    void Deslocar(float dx, float dy);

    virtual void setTipo();
    const string getTipo() const;

    virtual void mover(float dT);
    virtual void Executar(float dT);

    void Atualiza_Contador(float dT, bool zera = false);
};

#endif 