#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class UserInterface
{
private:

	sf::Text scoreTitle;
	sf::Text gameOver;
	sf::Text score;

	sf::Font font;

public:

	UserInterface();

	void update(int);
	void drawScoreTitle(sf::RenderWindow&);
	void drawScore(sf::RenderWindow& window);
	void drawEndScreen(sf::RenderWindow&);

};

