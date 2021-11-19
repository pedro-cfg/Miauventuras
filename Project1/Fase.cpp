#include "stdafx.h"
#include "Fase.h"

Fase::Fase() :
	Ente(),
	gerenciador_colisoes(&lista_entidades),
	pJ1(NULL),
	estado_jogo(NULL),
	reinicio(NULL)
{
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);
	Entidade::setPonteiroLista(&lista_entidades);
}

Fase::~Fase()
{
}

void Fase::Executar(float dT)
{
	Entidade::setPonteiroLista(&lista_entidades);
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);

	gerenciador_colisoes.Checa_Colisao(pJ1);
	gerenciador_colisoes.Checa_Colisao_Inimigos();

	pJ1->Executar(dT);
	lista_entidades.Executar(dT);

	pGG->AjustarVista(pJ1);

	pJ1->desenhar();
	pGG->DesenhaTudo(lista_entidades);

	Passou_Fase();
	if (pJ1->getVidas() <= 0)
	{
		pJ1->reseta_jogador(true);
		*reinicio = true;
		/*reseta_fase();*/
		*estado_jogo = 0;
	}
}

void Fase::Gerar_Objetos()
{
	srand(time(NULL));
	Gerar_Inimigos();
	Gerar_Obstaculos();
}

void Fase::Gerar_Inimigos()
{
	Gerar_Chefao();
	int instancias, posicao;

	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++)
	{
		posicao = (rand() % 9000) + 300;
		Aranha* pA = new Aranha((float)posicao, -1000);
		lista_entidades.Inserir(static_cast<Entidade*>(pA));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pA));
	}

	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++)
	{
		posicao = (rand() % 9000) + 300;
		Lagartixa* pL = new Lagartixa((float)posicao, -1000);
		lista_entidades.Inserir(static_cast<Entidade*>(pL));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pL));
	}
}

void Fase::Gerar_Obstaculos()
{
	Gerar_Plataformas();
	int instancias, posicao;

	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++) {
		posicao = (rand() % 9000) + 300;
		Espinho* pE = new Espinho((float)posicao, -75);
		lista_entidades.Inserir(static_cast<Entidade*>(pE));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pE));
	}

	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++) {
		posicao = (rand() % 9000) + 300;
		Teia* pT = new Teia((float)posicao, -200);
		lista_entidades.Inserir(static_cast<Entidade*>(pT));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pT));
	}
}

void Fase::Gerar_Plataformas()
{
}

void Fase::Gerar_Chefao()
{
}

void Fase::Inserir_Entidade(Entidade* pE)
{
	lista_entidades.Inserir(pE);
}

void Fase::reseta_fase()
{
	lista_entidades.Limpar();
	gerenciador_colisoes.LimpaListas();
	pJ1->reseta_jogador(true, true);

	Gerar_Objetos();
}

void Fase::Passou_Fase()
{
}

void Fase::setJogador(Jogador* pJ)
{
	pJ1 = pJ;
}

ListaEntidades& Fase::getLista()
{
	return lista_entidades;
}

void Fase::Limpar()
{
	lista_entidades.Limpar();
}

void Fase::GravarLista(fstream& arquivo)
{
	lista_entidades.Gravar(arquivo);
}

void Fase::LerLista(fstream& arquivo)
{
	Entidade::setPonteiroLista(&lista_entidades);
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);

	Limpar();
	gerenciador_colisoes.LimpaListas();

	int tamanho_lista;

	arquivo.read((char*)&tamanho_lista, sizeof(tamanho_lista));

	for (int i = 0; i < tamanho_lista; i++) {
		LerLista_Individual(arquivo);
	}

}

void Fase::LerLista_Individual(fstream& arquivo)
{
	string tipo;
	int tamanho_tipo;

	float x, y, Xinicial;
	int vidas;

	arquivo.read((char*)&tamanho_tipo, sizeof(tamanho_tipo));
	tipo.resize(tamanho_tipo);
	arquivo.read((char*)&tipo[0], tamanho_tipo);

	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));
	arquivo.read((char*)&Xinicial, sizeof(Xinicial));
	arquivo.read((char*)&vidas, sizeof(vidas));


	if (tipo == "Aranha") {
		Aranha* pA = new Aranha;
		pA->Recuperar(x, y, Xinicial, vidas);
	}
	else if (tipo == "Lagartixa") {
		Lagartixa* pL = new Lagartixa;
		pL->Recuperar(x, y, Xinicial, vidas);
	}
	else if (tipo == "Ratao") {
		Ratao* pR = new Ratao;
		pR->Recuperar(x, y, Xinicial, vidas);
	}
	else if (tipo == "Teia") {
		Teia* pT = new Teia;
		pT->Recuperar(x, y, Xinicial, vidas);
	}
	else if (tipo == "Espinho") {
		Espinho* pEsp = new Espinho;
		pEsp->Recuperar(x, y, Xinicial, vidas);
	}
	else if (tipo == "Plataforma") {
		Plataforma* pP = new Plataforma;
		pP->Recuperar(x, y, Xinicial, vidas);
	}
	else if (tipo == "Projetil") {
		Projetil* pP = new Projetil;
		pP->Recuperar(x, y, Xinicial, vidas);
	}
}
