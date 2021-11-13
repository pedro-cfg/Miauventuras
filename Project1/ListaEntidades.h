#ifndef _LISTAENTIDADES_H_
#define _LISTAENTIDADES_H_

#include "Lista.h"
#include "Entidade.h"

class ListaEntidades
{
public: 
    Lista<Entidade> LEs;
    ListaEntidades();
    ~ListaEntidades();

    void Inserir(Entidade* pE);
    void Retirar(Entidade* pE);

    void Executar(float dT);
    void Desenha();
};

#endif