#ifndef _LISTAENTIDADES_H_
#define _LISTAENTIDADES_H_

#include "Lista.h"

template <class Entidade>
class ListaEntidades{
public: 
    Lista<Entidade> LEs;
    ListaEntidades() {}
    ~ListaEntidades() {}
};

#endif