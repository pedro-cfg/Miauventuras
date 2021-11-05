/**
 * Project Untitled
 */


#ifndef _ELEMENTO_H
#define _ELEMENTO_H

template<Class TE >
class Elemento {
private: 
    Elemento<TE>* pProx;
    TE* pinfo;
};

#endif //_ELEMENTO_H