#include "Inimigo.h"

Inimigo::Inimigo():
	Personagem()
{
	setTipo();
	vidas = 1;
}

Inimigo::~Inimigo() 
{

}

void Inimigo::setTipo() {
	tipo = "Inimigo";
}


