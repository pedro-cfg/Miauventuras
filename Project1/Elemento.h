#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

template <class TE >
class Elemento {
private: 
    Elemento<TE>* pProx;
    TE* pinfo;
public:
    Elemento(TE* pv) {
		pinfo = pv;
		pProx = NULL;
	}
    ~Elemento() {}
	TE* getInfo() {
		return pinfo;
	}
	void setProx(Elemento* el) {
		pProx = el;
	}
	Elemento* getProx() {
		return pProx;
	}
};

#endif