#include "Game.h"

void Game::initializeWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 736;

	this->window = new sf::RenderWindow(this->videoMode, "PAC-MAN", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initializeMap()
{
	map.load("MapScheme.txt");
}

void Game::renderPacMan(sf::RenderWindow& window)
{
	pacMan.draw(window);
}

Game::Game()
{
	this->initializeWindow();
	this->initializeMap();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			else if (this->ev.key.code == sf::Keyboard::W)
				pacMan.move(sf::Vector2f(0, -1));
			else if (this->ev.key.code == sf::Keyboard::S)
				pacMan.move(sf::Vector2f(0, 1));
			else if (this->ev.key.code == sf::Keyboard::A)
				pacMan.move(sf::Vector2f(-1, 0));
			else if (this->ev.key.code == sf::Keyboard::D)
				pacMan.move(sf::Vector2f(1, 0));
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear(sf::Color::Black);

	map.draw(*window);

	pacMan.draw(*window);

	this->window->display();
}