#ifndef _MENU_H_
#define _MENU_H_

#include "Ente.h"
#include "Estado.h"

class FasePrimeira;
class Jogador;
class Jogo;

class Menu: public Ente, public Estado 
{
protected:
	static Jogo* pJogo;
	static bool dois_jogadores;

	int indice;

	int num_opcoes;
	int linhas_texto;

	sf::Font fonte;
	sf::Text texto[7];
public:
	Menu();
	virtual ~Menu();

	static void setPonteiroJogo(Jogo* pJ);

	virtual void InicializaTexto();
	
	void ExecutaEstado(float dT);
	virtual void Executar(float dT);
	void imprimir_se();

	virtual void Escolher_Opcao();

	float CalculaTamanho(sf::Text texto);

	void opcao_acima();
	void opcao_abaixo();

	virtual void incluiTexto(char letra);
	virtual void retiraTexto();

	void SalvarPontuacao();
};

#endif