#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico(Menu* pM) :
	janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!"),
	vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(LARGURA_EXIBICAO, ALTURA_EXIBICAO)),
	marcador1(0, 0),
	pM(pM)
{
	sf::RenderWindow janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!");
	sf::View vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(640.f, 360.f));
	textura_fundo.loadFromFile("Texturas/fundo1.png");
	fundo.setSize((sf::Vector2f)textura_fundo.getSize());
	fundo.setTexture(&textura_fundo);
	fundo.setPosition(sf::Vector2f(-1000.f,-1080.f));
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{

}

bool Gerenciador_Grafico::JanelaAberta()
{
	return janela.isOpen();
}

void Gerenciador_Grafico::RedimensionarVista()
{
	float razao = (float)janela.getSize().x / (float)janela.getSize().y;

	vista.setSize(ALTURA_EXIBICAO * razao, ALTURA_EXIBICAO);
}

void Gerenciador_Grafico::AjustarVista(Jogador* jogador)
{
	float coordY = jogador->getY();
	float coordX = jogador->getX() + 200.f;
	if (coordY > -380)
		coordY = -380;
	if (coordX < 57)
		coordX = 57;
	if (coordX > 8950)
		coordX = 8950;
	vista.setCenter(coordX, coordY);
	marcador1.getforma().setPosition(coordX + 800, coordY - 400);
	marcador1.AtualizaMarcador();
	DesenhaForma(fundo);
	DesenhaForma(marcador1.getforma());
}

void Gerenciador_Grafico::RestaurarVista()
{
	vista.setCenter(800.f,420.f);
}

void Gerenciador_Grafico::EventosJanela()
{
	sf::Event event;
	while (janela.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			janela.close();
			break;
		case sf::Event::Resized:
			RedimensionarVista();
			break;
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				pM->opcao_acima();
				break;
			case sf::Keyboard::S:
				pM->opcao_abaixo();
				break;
			case sf::Keyboard::Space:
				pM->Escolher_Opcao(janela);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void Gerenciador_Grafico::DesenhaTexto(sf::Text* texto)
{
	janela.draw(*texto);
	janela.draw(*(texto + 1));
	janela.draw(*(texto + 2));
	janela.setView(vista);
}

void Gerenciador_Grafico::DesenhaForma(sf::RectangleShape& forma)
{
	janela.draw(forma);
}

void Gerenciador_Grafico::DesenhaTudo(ListaEntidades& lista)
{
	lista.Desenha();
	janela.setView(vista);
}

void Gerenciador_Grafico::LimparTela()
{
	janela.display();
	janela.clear();
}

Gerenciador_Grafico::Marcador_Vida* Gerenciador_Grafico::getMarcador()
{
	return &marcador1;
}

Gerenciador_Grafico::Marcador_Vida::Marcador_Vida(float x1, float y1):
	x(0),y(0), pJogador(NULL)
{
	x = x1;
	y = y1;

	textura_1.loadFromFile("Texturas/Numeros/numero1.png");
	textura_2.loadFromFile("Texturas/Numeros/numero2.png");
	textura_3.loadFromFile("Texturas/Numeros/numero3.png");

	forma_marcador.setSize((sf::Vector2f)textura_3.getSize());
	forma_marcador.setTexture(&textura_3);
	forma_marcador.setOrigin(forma_marcador.getSize() / 2.0f);
	forma_marcador.setPosition(sf::Vector2f(x, y));
}

Gerenciador_Grafico::Marcador_Vida::~Marcador_Vida()
{
}

void Gerenciador_Grafico::Marcador_Vida::setJogador(Jogador* pJ)
{
	pJogador = pJ;
}

void Gerenciador_Grafico::Marcador_Vida::AtualizaMarcador()
{
	int vidas = pJogador->getVidas();
	
	switch (vidas)
	{
	case 3:
		forma_marcador.setTexture(&textura_3);
		break;
	case 2:
		forma_marcador.setTexture(&textura_2);
		break;
	case 1:
		forma_marcador.setTexture(&textura_1);
		break;
	}
}

sf::RectangleShape& Gerenciador_Grafico::Marcador_Vida::getforma()
{
	return forma_marcador;
}

