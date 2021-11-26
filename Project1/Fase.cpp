#include "stdafx.h"
#include "Fase.h"
#include "Gerenciador_Grafico.h"
using namespace Menus;

Fase::Fase() :
	Ente(),
	Estado(),
	gerenciador_colisoes(&lista_entidades),
	pJ1(NULL),
	pJ2(NULL)
{
}

Fase::~Fase()
{
	pJ1 = NULL;
	pJ2 = NULL;
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

	/*Alcance de instâncias: 3-5*/
	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++)
	{
		posicao = (rand() % 9000) + 300;
		Aranha* pA = new Aranha((float)posicao, -1000);
		lista_entidades.Inserir(static_cast<Entidade*>(pA));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pA));
	}

	/*Alcance de instâncias: 3-5*/
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

	/*Alcance de instâncias: 3-5*/
	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++) {
		posicao = (rand() % 9000) + 300;
		Espinho* pE = new Espinho((float)posicao, -75);
		lista_entidades.Inserir(static_cast<Entidade*>(pE));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pE));
	}

	/*Alcance de instâncias: 3-5*/
	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++) {
		posicao = (rand() % 9000) + 300;
		Teia* pT = new Teia((float)posicao, -200);
		lista_entidades.Inserir(static_cast<Entidade*>(pT));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pT));
	}
}

void Fase::Inserir_Entidade(Entidade* pE)
{
	lista_entidades.Inserir(pE);
}

void Fase::reseta_fase(Jogador1* p1, Jogador2* p2, bool reinicio)
{
	lista_entidades.Limpar();
	gerenciador_colisoes.LimpaListas();
	pJ1 = p1;
	pJ2 = p2;
	if (pJ1)
	{
		if (reinicio)
			pJ1->reseta_jogador(true, true);
		else
			pJ1->reseta_jogador();
	}
	if (pJ2)
	{
		if (reinicio)
			pJ2->reseta_jogador(true, true);
		else
			pJ2->reseta_jogador();
	}

	Gerar_Objetos();

	Entidade::setPonteiroLista(&lista_entidades);
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);
}

void Fase::MorteJogadores()
{
	if (pJ1 && pJ1->Morreu())
	{
		pJ1->reseta_jogador();
		pJ1 = NULL;
	}
	if (pJ2 && pJ2->Morreu())
	{
		pJ2->reseta_jogador();
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
	pJ1 = NULL;
	pJ2 = NULL;
	gerenciador_colisoes.LimpaListas();
}

void Fase::Gravar()
{
	GravarJogadores();
	LimparArquivos();
	GravarEntidades();
}

void Fase::GravarJogadores()
{
	fstream arquivo;
	arquivo.open("Persistencia/JogadoresFase.bin", ios::binary | ios::out | ios::trunc);

	bool p1 = false, p2 = false;
	if (pJ1)
		p1 = true;
	if (pJ2)
		p2 = true;
	arquivo.write((char*)&p1, sizeof(p1));
	arquivo.write((char*)&p2, sizeof(p2));

	arquivo.close();
}

void Fase::GravarEntidades()
{
	lista_entidades.Gravar();
}

void Fase::LimparArquivos()
{
	fstream limpo;
	limpo.open("Persistencia/Aranhas.bin", ios::binary | ios::trunc);
	limpo.close();

	limpo.open("Persistencia/Espinhos.bin", ios::binary | ios::trunc);
	limpo.close();

	limpo.open("Persistencia/Lagartixas.bin", ios::binary | ios::trunc);
	limpo.close();

	limpo.open("Persistencia/Plataformas.bin", ios::binary | ios::trunc);
	limpo.close();

	limpo.open("Persistencia/Projeteis.bin", ios::binary | ios::trunc);
	limpo.close();

	limpo.open("Persistencia/Ratao.bin", ios::binary | ios::trunc);
	limpo.close();

	limpo.open("Persistencia/Teias.bin", ios::binary | ios::trunc);
	limpo.close();
}

void Fase::Carregar(Jogador1* p1, Jogador2* p2)
{
	Entidade::setPonteiroLista(&lista_entidades);
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);
	Limpar();

	CarregarJogadores(p1, p2);
	CarregarEntidades();
}

void Fase::CarregarEntidades()
{
	CarregarInimigos();
	CarregarObstaculos();
	CarregarProjeteis();
}

void Fase::CarregarJogadores(Jogador1* p1, Jogador2* p2)
{
	fstream arquivo;
	arquivo.open("Persistencia/JogadoresFase.bin", ios::binary | ios::in);

	bool j1 = false, j2 = false;
	arquivo.read((char*)&j1, sizeof(j1));
	arquivo.read((char*)&j2, sizeof(j2));

	if (j1)
		pJ1 = p1;
	if (j2)
		pJ2 = p2;

	arquivo.close();
}

void Fase::CarregarInimigos()
{
	fstream arquivo;

	arquivo.open("Persistencia/Aranhas.bin", ios::binary | ios::in);
	while (!arquivo.eof())
	{
		Aranha* pAux = new Aranha();

		pAux->Carregar(arquivo);

		lista_entidades.Inserir(static_cast<Entidade*>(pAux));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pAux));
	}
	arquivo.close();

	cout << lista_entidades.LEs.Quantidade() << endl;

	arquivo.open("Persistencia/Lagartixas.bin", ios::binary | ios::in);
	while (!arquivo.eof())
	{
		Lagartixa* pAux = new Lagartixa();

		pAux->Carregar(arquivo);

		lista_entidades.Inserir(static_cast<Entidade*>(pAux));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pAux));
	}
	arquivo.close();

	cout << lista_entidades.LEs.Quantidade() << endl;

	arquivo.open("Persistencia/Ratao.bin", ios::binary | ios::in);
	while (!arquivo.eof())
	{
		Ratao* pAux = new Ratao();

		pAux->Carregar(arquivo);

		lista_entidades.Inserir(static_cast<Entidade*>(pAux));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pAux));
	}
	arquivo.close();

	cout << lista_entidades.LEs.Quantidade() << endl;
}

void Fase::CarregarObstaculos()
{
	fstream arquivo;

	arquivo.open("Persistencia/Espinhos.bin", ios::binary | ios::in);
	while (!arquivo.eof())
	{
		Espinho* pAux = new Espinho();

		pAux->Carregar(arquivo);

		lista_entidades.Inserir(static_cast<Entidade*>(pAux));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pAux));
	}
	arquivo.close();

	cout << lista_entidades.LEs.Quantidade() << endl;

	arquivo.open("Persistencia/Plataformas.bin", ios::binary | ios::in);
	while (!arquivo.eof())
	{
		Plataforma* pAux = new Plataforma();

		pAux->Carregar(arquivo);

		lista_entidades.Inserir(static_cast<Entidade*>(pAux));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pAux));
	}
	arquivo.close();

	cout << lista_entidades.LEs.Quantidade() << endl;

	arquivo.open("Persistencia/Teias.bin", ios::binary | ios::in);
	while (!arquivo.eof())
	{
		Teia* pAux = new Teia();

		pAux->Carregar(arquivo);

		lista_entidades.Inserir(static_cast<Entidade*>(pAux));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pAux));
	}
	arquivo.close();

	cout << lista_entidades.LEs.Quantidade() << endl;
}

void Fase::CarregarProjeteis()
{
	fstream arquivo;

	arquivo.open("Persistencia/Projeteis.bin", ios::binary | ios::in);
	while (!arquivo.eof())
	{
		Projetil* pAux = new Projetil();

		pAux->Carregar(arquivo);

		lista_entidades.Inserir(static_cast<Entidade*>(pAux));
		gerenciador_colisoes.Inserir(pAux);
	}
	arquivo.close();
}