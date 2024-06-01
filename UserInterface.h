#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class UserInterface
{
private:

	sf::Text score;
	sf::Font font;
	sf::Text gameOver;

public:

	UserInterface();

	void draw(sf::RenderWindow& window);
	void update(int);
	void endScreen(sf::RenderWindow&);

};

