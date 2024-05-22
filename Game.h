#pragma once

#include "Map.h"
#include "PacMan.h"

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Vector2f desiredMove = sf::Vector2f(0.0f, 0.0f);

	sf::Text score;
	sf::Font font;

	int points = 0;

	Map map;

	PacMan pacMan;

	void initializeWindow();

	void initializeMap();

	void renderPacMan(sf::RenderWindow& window);

	void initializeUserInterface();

public:

	Game();
	virtual ~Game();

	const bool running() const;

	void pollEvents();
	void update();
	void render();

	// Draft
	void maintenceMode();
};