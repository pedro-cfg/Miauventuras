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
public: 
    Entidade();
    virtual~Entidade();

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

    /*Métodos executados polimorficamente*/
    virtual void mover(float dT){}
    virtual void Executar(float dT) = 0;

    virtual void Gravar(){}
    virtual void GravarInfo(fstream& arquivo){}
    virtual void Carregar(fstream& arquivo){}
};

#endif 