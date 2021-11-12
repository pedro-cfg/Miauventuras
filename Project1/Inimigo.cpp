#include "Inimigo.h"

Inimigo::Inimigo():
	Personagem()
{
	setTipo();
}

Inimigo::~Inimigo() 
{

}

void Inimigo::setTipo() {
	tipo = "Inimigo";
}


