#include "UserInterface.h"

UserInterface::UserInterface()
{
	if (!font.loadFromFile("fonts/Sign Rover Layered.ttf")) std::cerr << "Error loading font \n";
	score.setFont(font);
	score.setCharacterSize(24);
	score.setFillColor(sf::Color::White);
	score.setPosition(85, 10);

	gameOver.setFont(font);
	gameOver.setCharacterSize(72);
	gameOver.setFillColor(sf::Color::White);
	gameOver.setPosition(185, 400);
	gameOver.setString("Game Over");

	scoreTitle.setFont(font);
	scoreTitle.setCharacterSize(24);
	scoreTitle.setFillColor(sf::Color::White);
	scoreTitle.setPosition(10, 10);
	scoreTitle.setString("Score: ");
}

void UserInterface::update(int points)
{
	this->score.setString(std::to_string(points));
}

void UserInterface::drawScoreTitle(sf::RenderWindow& window)
{
	window.draw(scoreTitle);
}

void UserInterface::drawScore(sf::RenderWindow& window)
{
	window.draw(score);
}

void UserInterface::drawEndScreen(sf::RenderWindow& window)
{	
	window.draw(gameOver);
}
