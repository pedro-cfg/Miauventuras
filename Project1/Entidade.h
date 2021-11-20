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

    sf::RectangleShape forma;

    static Gerenciador_Colisoes* pGC;
    static ListaEntidades* pLista;

    string tipo;

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

    void Reposicionar(float X, float Y);
    void Deslocar(float dx, float dy);

    virtual void setTipo();
    const string getTipo() const;

    virtual void mover(float dT);
    virtual void Executar(float dT);

    virtual void Recuperar(float cX, float cY, float XI = 0.f, int numVidas = 0, float velX = 0.f, float velY = 0.f);
};

#endif 