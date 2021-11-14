#ifndef _LISTAENTIDADES_H_
#define _LISTAENTIDADES_H_

#include "Lista.h"

class Entidade;

class ListaEntidades
{
private:
    Lista<Entidade> LEs;
public: 
    ListaEntidades();
    ~ListaEntidades();

    void Inserir(Entidade* pE);
    void Retirar(Entidade* pE);

    void Executar(float dT);
    void Desenha();
};

#endif