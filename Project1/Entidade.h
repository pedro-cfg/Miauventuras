#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "Ente.h"

class Entidade: public Ente {
protected:
    int x;
    int y;
public: 
    Entidade();
    ~Entidade();
};

#endif 