#ifndef _LISTAENTIDADES_H_
#define _LISTAENTIDADES_H_

#include "Lista.h"
#include "Inimigo.h"
#include "Projetil.h"

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

    void Limpar();

    void Gravar(fstream& arquivo);
    void Gravar_Individual(Entidade* pE, fstream& arquivo);

    ///*Limpa a lista a partir de um determinado índice ind*/
    //void Limpar(int ind = 0);
};

#endif