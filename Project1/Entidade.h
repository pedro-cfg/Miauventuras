/**
 * Project Untitled
 */


#ifndef _ENTIDADE_H
#define _ENTIDADE_H

#include "Ente.h"


class Entidade: public Ente {
public: 
    
void Entidade();
    
void Entidade();
    
virtual virtual void executar() = 0;
protected: 
    int x;
    int y;
};

#endif //_ENTIDADE_H