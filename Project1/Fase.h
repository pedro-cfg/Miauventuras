/**
 * Project Untitled
 */


#ifndef _FASE_H
#define _FASE_H

#include "Ente.h"


class Fase: public Ente {
public: 
    
virtual virtual void excutar() = 0;
    
void gerenciar_colisoes();
};

#endif //_FASE_H