#include "stdafx.h"
#include "Fase.h"
#include "Gerenciador_Grafico.h"

Fase::Fase() :
	Ente(),
	gerenciador_colisoes(&lista_entidades),
	pJ1(NULL),
	pJ2(NULL)
{
}

Fase::~Fase()
{
}

void Fase::ExecutaEstado(float dT)
{
	this->Executar(dT);
}

void Fase::Executar(float dT)
{
	if (pJ1)
	{
		gerenciador_colisoes.Checa_Colisao(static_cast<Jogador*>(pJ1));
		pJ1->Executar(dT);
	}
	if (pJ2)
	{
		gerenciador_colisoes.Checa_Colisao(static_cast<Jogador*>(pJ2));
		pJ2->Executar(dT);
	}
	gerenciador_colisoes.Checa_Colisao_Inimigos();

	lista_entidades.Executar(dT);

	pGG->AjustarVista(pJ1, pJ2);

	pGG->DesenhaTudo(lista_entidades, pJ1, pJ2);

	Passou_Fase();
	MorteJogadores();
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

void Fase::reseta_fase(Jogador1* p1, Jogador2* p2)
{
	lista_entidades.Limpar();
	gerenciador_colisoes.LimpaListas();
	pJ1 = p1;
	pJ2 = p2;
	if (pJ1)
	{
		pJ1->reseta_jogador();
	}
	if (pJ2)
	{
		pJ2->reseta_jogador();
	}

	Gerar_Objetos();

	Entidade::setPonteiroLista(&lista_entidades);
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);
}

void Fase::Passou_Fase()
{
}

void Fase::MorteJogadores()
{
	if (pJ1 && pJ1->Morreu())
	{
		pJ1->reseta_jogador(true, true);
		pJ1 = NULL;
	}
	if (pJ2 && pJ2->Morreu())
	{
		pJ2->reseta_jogador(true, true);
		pJ2 = NULL;
	}
	if (!(pJ1 || pJ2))
	{
		pMaquinaEstados->setEstadoAtual(MENU_FIM);
		MenuFim* pMenu = static_cast<MenuFim*>(pMaquinaEstados->getEstadoAtual());
		pMenu->setVitoria(false);
	}
}

void Fase::Limpar()
{
	lista_entidades.Limpar();
}

void Fase::GravarLista(fstream& arquivo)
{
	lista_entidades.Gravar(arquivo);
}

void Fase::LerLista(fstream& arquivo, Jogador1* p1, Jogador2* p2)
{
	Entidade::setPonteiroLista(&lista_entidades);
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);

	Limpar();
	gerenciador_colisoes.LimpaListas();

	int tamanho_lista;

	pJ1 = p1;
	pJ2 = p2;

	arquivo.read((char*)&tamanho_lista, sizeof(tamanho_lista));

	for (int i = 0; i < tamanho_lista; i++) {
		LerLista_Individual(arquivo);
	}

}

void Fase::LerLista_Individual(fstream& arquivo)
{
	string tipo;
	int tamanho_tipo;

	float x, y, Xinicial, velX, velY;
	int vidas;

	arquivo.read((char*)&tamanho_tipo, sizeof(tamanho_tipo));
	tipo.resize(tamanho_tipo);
	arquivo.read((char*)&tipo[0], tamanho_tipo);

	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));
	arquivo.read((char*)&Xinicial, sizeof(Xinicial));
	arquivo.read((char*)&vidas, sizeof(vidas));
	arquivo.read((char*)&velX, sizeof(velX));
	arquivo.read((char*)&velY, sizeof(velY));

	if (tipo == "Aranha") {
		Aranha* pA = new Aranha;
		pA->Recuperar(x, y, Xinicial, vidas, velX, velY);
	}
	else if (tipo == "Lagartixa") {
		Lagartixa* pL = new Lagartixa;
		pL->Recuperar(x, y, Xinicial, vidas, velX, velY);
	}
	else if (tipo == "Ratao") {
		Ratao* pR = new Ratao;
		pR->Recuperar(x, y, Xinicial, vidas, velX, velY);
	}
	else if (tipo == "Teia") {
		Teia* pT = new Teia;
		pT->Recuperar(x, y, Xinicial, vidas, velX, velY);
	}
	else if (tipo == "Espinho") {
		Espinho* pEsp = new Espinho;
		pEsp->Recuperar(x, y, Xinicial, vidas, velX, velY);
	}
	else if (tipo == "Plataforma") {
		Plataforma* pP = new Plataforma;
		pP->Recuperar(x, y, Xinicial, vidas, velX, velY);
	}
	else if (tipo == "Projetil") {
		Projetil* pP = new Projetil;
		pP->Recuperar(x, y, Xinicial, vidas, velX, velY);
	}
}
