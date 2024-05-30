#pragma once

#include <SFML/Graphics.hpp>

class PacMan {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f currentDirection;
    sf::Vector2f desiredDirection;

    sf::CircleShape shape;
    sf::Color color;

public:
    PacMan();

    void setDesiredMove(sf::Vector2f);
    void move();
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition();
    float getRadius();
    sf::Vector2f getDesiredMove();
    void setCurrentDirection(sf::Vector2f);
};


