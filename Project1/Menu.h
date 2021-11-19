#ifndef _MENU_H_
#define _MENU_H_

#include "Ente.h"

class FasePrimeira;

class Menu: public Ente 
{
private:
	int indice;
	int& estado_jogo;
	sf::Font fonte;
	sf::Text texto[5];
	//FasePrimeira* pF;
public:
	//Menu(float largura, float altura, FasePrimeira* pFase);
	Menu(float largura, float altura, int& estado);

	~Menu();

	void InicializaTexto(float largura, float altura);

	void Executar(float dT);
	void imprimir_se();

	void Escolher_Opcao();

	void opcao_acima();
	void opcao_abaixo();
};

#endif