#include "UserInterface.h"

UserInterface::UserInterface()
{
	if (!font.loadFromFile("fonts/Sign Rover Layered.ttf")) std::cerr << "Error loading font \n";
	score.setFont(font);
	score.setCharacterSize(24);
	score.setFillColor(sf::Color::White);
	score.setPosition(10, 10);
}

void UserInterface::draw(sf::RenderWindow& window)
{
	window.draw(score);
}

void UserInterface::update(int points)
{
	this->score.setString(std::to_string(points));
}

void UserInterface::endScreen(sf::RenderWindow& window)
{
	if (!font.loadFromFile("fonts/Sign Rover Layered.ttf")) std::cerr << "Error loading font \n";
	gameOver.setFont(font);
	gameOver.setCharacterSize(72);
	gameOver.setFillColor(sf::Color::White);
	gameOver.setPosition(185, 400);
	gameOver.setString("Game Over");
	window.draw(gameOver);
}
