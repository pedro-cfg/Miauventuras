#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	gerenciador_colisoes(&j1)
{
	Inserir_Colisao();
	while (gerenciador_grafico.JanelaAberta()) {
		gerenciador_grafico.Fechar_Redimensionar();
		gerenciador_colisoes.Checa_Colisao();
		gerenciador_grafico.Mover_Teclado(&gerenciador_colisoes, &j1);
		gerenciador_grafico.Desenha(&j1, &a1, &l1, &r1);
	}
}

Jogo::~Jogo() {

}

void Jogo::Inserir_Colisao()
{
	gerenciador_colisoes.InserirInimigo(&a1);
	gerenciador_colisoes.InserirInimigo(&l1);
	gerenciador_colisoes.InserirInimigo(&r1);
}
