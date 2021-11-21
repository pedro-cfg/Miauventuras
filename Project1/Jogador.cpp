#include "Jogador.h"
#include "Gerenciador_Colisoes.h"
#include "Gerenciador_Grafico.h"

Jogador::Jogador() :
	Personagem(),
	nome("")
{
	pontos = 0;
	vidas = 7;

	//CarregaTextura(JOGADOR1);
	//forma.setPosition(sf::Vector2f(x, y));
	//this->x = x;
	//this->y = y;

	reseta_velocidade();

	alturaPulo = 350.0f;
	podePular = true;
	empurrado = false;

	venceu = false;

	fase = 1;
}

Jogador::~Jogador()
{

}

void Jogador::Executar(float dT)
{
	mover(dT);
	Atualiza_Contador(dT);
}

void Jogador::mover(float dT)
{
	if (!empurrado)
		velocidadeX = 0.0f;

	if (colidiu_cima)
	{
		velocidadeY = 0.0f;
	}

	if (!colidiu_baixo && abs(y) >= getAltura() / 2.f)
	{
		velocidadeY += 981.0f * dT;
	}
	else if (!empurrado)
	{
		podePular = true;
		velocidadeY = 0.0f;
	}

	if (colidiu_baixo || abs(y) <= getAltura() / 2.f)
		empurrado = false;

	if (mover_dir())
	{
		if (!colidiu_direita && !empurrado)
			velocidadeX += velocidadeEscalar;
	}
	if (mover_esq())
	{
		if (!colidiu_esquerda && !empurrado)
			velocidadeX -= velocidadeEscalar;
	}
	if (pular() && podePular && !empurrado)
	{
		podePular = false;
		velocidadeY = -sqrt(2.0f * 981.0f * alturaPulo);
	}

	float dx = velocidadeX * dT;
	float dy = velocidadeY * dT;

	Deslocar(dx, dy);
}

bool Jogador::mover_esq()
{
	return false;
}

bool Jogador::mover_dir()
{
	return false;
}

bool Jogador::pular()
{
	return false;
}

void Jogador::reseta_jogador(const bool resetaPontos, const bool resetaVidas)
{
	if (resetaPontos)
		pontos = 0;
	reseta_colidiu();
	reseta_velocidade();
	if (resetaVidas)
		vidas = 7;
	forma.setPosition(0, -100);
	x = 0;
	y = -100;
	venceu = false;
}

void Jogador::reseta_velocidade()
{
	velocidadeEscalar = 400.0f;
}

void Jogador::setEmpurrado(bool emp)
{
	empurrado = emp;
}

void Jogador::setVenceu(const bool v)
{
	venceu = v;
}

bool Jogador::getVenceu() const
{
	return venceu;
}

bool Jogador::Morreu() const
{
	return (vidas <= 0);
}

void Jogador::Pontua(Inimigo* pI)
{
	int valorInimigo = pI->getValor();
	for (int i = 0; i < valorInimigo; i++)
	{
		this->operator++();
	}
	/*Temporário!!!!!*/
	cout << pontos << endl;
}

void Jogador::operator++()
{
	pontos++;
}

void Jogador::setTipo()
{
	tipo = "Jogador";
}

const int Jogador::getFase() const
{
	return fase;
}

void Jogador::setFase(int f)
{
	fase = f;
}

void Jogador::setNome(string n)
{
	n.pop_back();
	nome = n;
}

void Jogador::setPontuacao(int pont)
{
	pontos = pont;
}

const int Jogador::getPontuacao() const
{
	return pontos;
}

const string Jogador::getNome() const
{
	return nome;
}
