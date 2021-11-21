#ifndef _MENU_H_
#define _MENU_H_

#include "Ente.h"

class FasePrimeira;
class Jogador;

class Menu: public Ente 
{
private:
	int indice;
	int* estado_jogo;
	bool* dois_jogadores;
	int estado_menu;
	int tamanho_texto;
	bool inicializar;

	Jogador* pJ1;
	Jogador* pJ2;

	sf::Font fonte;
	sf::Text texto[7];
	string placar[5];
public:
	Menu(int* estado, bool* dois_j);
	~Menu();

	void setJogadores(Jogador* pJog1, Jogador* pJog2);

	void InicializaTexto();
	
	void Executar(float dT);
	void imprimir_se();

	void setTamanhoTexto(int tam);
	void setEstadoMenu(int estado);
	void setInicializar(bool ini);

	void Escolher_Opcao();

	float CalculaTamanho(sf::Text texto);

	void opcao_acima();
	void opcao_abaixo();

	const int getEstado() const;

	void incluiTexto(char letra);
	void retiraTexto();

	void SalvarPontuacao();
	void RecuperarPontuacao();
};

#endif