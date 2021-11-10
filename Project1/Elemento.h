#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

template <class TE >
class Elemento 
{
private: 
    Elemento<TE>* pProx;
    TE info;
public:
    Elemento(TE info) 
	{
		this->info = info;
		pProx = nullptr;
	}
    ~Elemento() {}
	TE getInfo() 
	{
		return info;
	}
	void setProx(Elemento* el)
	{
		pProx = el;
	}
	Elemento* getProx() 
	{
		return pProx;
	}
};

#endif